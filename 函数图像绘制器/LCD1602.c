#include "LCD1602.h"

//????:
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_EN=P2^7;
#define LCD_DataPort P0


void LCD_Delay()
{
    unsigned char i, j;

    i = 2;
    j = 239;
    do
    {
        while (--j);
    } while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
    LCD_RS=0;
    LCD_RW=0;
    LCD_DataPort=Command;
    LCD_EN=1;
    LCD_Delay();
    LCD_EN=0;
    LCD_Delay();
}


void LCD_WriteData(unsigned char Data)
{
    LCD_RS=1;
    LCD_RW=0;
    LCD_DataPort=Data;
    LCD_EN=1;
    LCD_Delay();
    LCD_EN=0;
    LCD_Delay();
}


void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
    if(Line==1)
    {
        LCD_WriteCommand(0x80|(Column-1));
    }
    else if(Line==2)
    {
        LCD_WriteCommand(0x80|(Column-1+0x40));
    }
}


void LCD_Init()
{
    LCD_WriteCommand(0x38);//??????,????,5*7??
    LCD_WriteCommand(0x0c);//???,???,???
    LCD_WriteCommand(0x06);//???????,??????,????
    LCD_WriteCommand(0x01);//????,??
}


void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char)
{
    LCD_SetCursor(Line,Column);
    LCD_WriteData(Char);
}


//////////////////////////////////////////////////////////////////////////////////

void Initial_M096128x64_ssd1306()
{
	Delay_50ms(5);
	Write_IIC_Command(0xAE);   //display off
	Write_IIC_Command(0x02);	//Set Memory Addressing Mode	
	Write_IIC_Command(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	Write_IIC_Command(0x40);	//Set Page Start Address for Page Addressing Mode,0-7
	Write_IIC_Command(0xb0);	//Set COM Output Scan Direction
	Write_IIC_Command(0x81);//---set low column address
	Write_IIC_Command(0xff);//---set high column address
	Write_IIC_Command(0xa1);//--set start line address
	Write_IIC_Command(0xa6);//--set contrast control register
	Write_IIC_Command(0xa8);
	Write_IIC_Command(0x3f);//--set segment re-map 0 to 127
	Write_IIC_Command(0xad);//--set normal display
	Write_IIC_Command(0x8b);//--set multiplex ratio(1 to 64)
	Write_IIC_Command(0x33);//
	Write_IIC_Command(0xc8);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	Write_IIC_Command(0xd3);//-set display offset
	Write_IIC_Command(0x00);//-not offset
	Write_IIC_Command(0xd5);//--set display clock divide ratio/oscillator frequency
	Write_IIC_Command(0x80);//--set divide ratio
	Write_IIC_Command(0xd9);//--set pre-charge period
	Write_IIC_Command(0x1f); //
	Write_IIC_Command(0xda);//--set com pins hardware configuration
	Write_IIC_Command(0x12);
	Write_IIC_Command(0xdb);//--set vcomh
	Write_IIC_Command(0x40);//0x20,0.77xVcc
//	Write_IIC_Command(0x8d);//--set DC-DC enable
//	Write_IIC_Command(0x14);//
	Write_IIC_Command(0xaf);//--turn on oled panel 
}
void IIC_Stop()
{
   SCL = low;
   SDA = low;
   SCL = high;
   SDA = high;
}

void IIC_Start()
{
   SCL = high;		
   SDA = high;
   SDA = low;
   SCL = low;
}
void Delay_1ms(unsigned int Del_1ms)
{
	unsigned char j;
	while(Del_1ms--)
	{	
		for(j=0;j<123;j++);
	}
}

void Delay_50ms(unsigned int Del_50ms)
{
	unsigned int m;
	for(;Del_50ms>0;Del_50ms--)
		for(m=6245;m>0;m--);
}

void Write_IIC_Data(unsigned char IIC_Data)
{
   IIC_Start();
   Write_IIC_Byte(0x78);			//D/C#=0; R/W#=0
   Write_IIC_Byte(0x40);			//write data
   Write_IIC_Byte(IIC_Data);
   IIC_Stop();
}

void Write_IIC_Command(unsigned char IIC_Command)
{
   IIC_Start();
   Write_IIC_Byte(0x78);            //Slave address,SA0=0
   Write_IIC_Byte(0x00);			//write command
   Write_IIC_Byte(IIC_Command);
   IIC_Stop();
}

void Write_IIC_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)//对应8位，1字节数据，每次循环发送一个位
	{
		if(IIC_Byte & 0x80)
		SDA=high;
		else
		SDA=low;

		SCL=high;
		SCL=low;
		IIC_Byte<<=1;// IIC_Byte = IIC_Byte << 1;
	}
	SDA=1;
	SCL=1;
	SCL=0;
}


