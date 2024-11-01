
#include <REGX52.H>
//��������LCD_1602����
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);



//����ԭ����oled�����ݣ���ת������

#define high 1
#define low 0 
sbit SCL=P2^0;
sbit SDA=P2^1;


void Initial_M096128x64_ssd1306();

void Delay_50ms(unsigned int Del_50ms);
void Delay_1ms(unsigned int Del_1ms);

void IIC_Start();
void IIC_Stop();

void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);


