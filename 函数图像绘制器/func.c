#include "func.h"

char M;//��������
char N;//��������
float Z;//��������

signed char getkey()
{
    P1=0xFF;
    P1_3=0;
    if(P1_7==0)return 1;
    if(P1_6==0)return 5;
    if(P1_5==0)return 9;

    P1=0xFF;
    P1_2=0;
    if(P1_7==0)return 2;
    if(P1_6==0)return 6;
    if(P1_5==0)return 10;

    P1=0xFF;
    P1_1=0;
    if(P1_7==0)return 3;
    if(P1_6==0)return 7;
    if(P1_5==0)return 11;

    P1=0xFF;
    P1_0=0;
    if(P1_7==0)return 4;
    if(P1_6==0)return 8;
    if(P1_5==0)return 12;

    return 0;
}

void Delay100ms(void)	//@11.0592MHz
{
    int i=30000;
    while(i--);
}

void input_bit_0(signed char *a,signed char *i)//????  ??0??and 11110111
{
    signed char  i1;
    signed char  temp;
    i1=1;
    i1<<=(7-(*i));
    temp=(*a)&(~i1);
    LCD_ShowChar(2, (*i)+1, '0');
    (*a)=temp;
    (*i)++;
}

void input_bit_1(signed char *a,signed char *i)//????  ??1??or 00010000
{
    signed char i1;
    signed char temp;
    i1=1;
    i1<<=(7-(*i));
    temp=(*a)|i1;
    LCD_ShowChar(2, (*i)+1, '1');
    (*a)=temp;
    (*i)++;
}

void delete_bit(signed char *a,signed char *i,signed char function[],signed char *function_position)
{
    signed char i1;
    signed char temp;
    signed char b;
    (*i)--;
    LCD_Init();
    temp=(*a);
    for( i1=0; i1<(*i); i1++)
    {
        b=temp&0x80;
        b==0? (LCD_ShowChar(2, i1+1,'0')): (LCD_ShowChar(2, i1+1,'1'));
        temp=temp<<1;
    }

    for(i1=0; i1<(*function_position); i1++)
        LCD_ShowChar(1, i1+1,function[i1]);
}

void show_ASCII(signed char *a,signed char *i)
{
    if(*i==8)
        LCD_ShowChar(2,10, *a);
}


void confirm_bit(signed char *a, signed char *i,signed char function[],signed char *function_position)
{
    signed char k;
    LCD_Init();
    if((*a)!=0) function[(*function_position)++]=(*a);
    for(k=0; k<(*function_position); k++)
        LCD_ShowChar(1, k+1,function[k]);
	//(*function_position)++;
    *i=0;
}
void delete_function(signed char function[],signed char *function_position)
{
    signed char k;
    LCD_Init();
    (*function_position)--;
    for(k=0; k<(*function_position); k++)
        LCD_ShowChar(1, k+1,function[k]);
}
void judge_signature(signed char function[],signed char *stack_p,signed char stack_temp[], signed char *stack_temp_p,signed char *i)
{
    signed char a;
    switch(function[*i])
    {
    case ')':
        (*stack_temp_p)--;
        while(stack_temp[*stack_temp_p]!=-13)
            function[ (*stack_p)++]=stack_temp[(*stack_temp_p)--];
        break;
    
		case '(':
        stack_temp[(*stack_temp_p)++]=-13;
        break;
		
    case '+'://43
    case '-'://45
    {
        function[*i]=='+'?(a=-9):(a=-10);

        //����ʱջ����ķ���һһȡ��
        while((*stack_temp_p)!=0&&stack_temp[(*stack_temp_p)-1]!=-13)
        {
            function[(*stack_p)++]=stack_temp[(*stack_temp_p)-1];
            (*stack_temp_p)--;
        }
        stack_temp[(*stack_temp_p)++]=a;

        break;
    }
    case '*'://    *  42    /  47     (
		case '/':
    			function[*i]=='*'?(a=-11):(a=-12);
        //����ʱջ����ķ���һһȡ��
		while(stack_temp[(*stack_temp_p)-1]==-11||stack_temp[(*stack_temp_p)-1]==-12)
        {
            function[(*stack_p)++]=stack_temp[(*stack_temp_p)-1];
            (*stack_temp_p)--;
        }
        stack_temp[(*stack_temp_p)++]=a;
    }
}

void judge_number(signed char function[],signed char *function_position,signed char *stack_p, signed char *i)
{

    signed char num;
    signed char a[2];
    a[0]=0;
    while( 48<=function[*i]&&function[*i]<=57&&(*i)!=(*function_position))
    {
        a[1]=a[0];
        a[0]=function[(*i)++]-'0';//a[0],a[1]
    }
    num=a[1]*10+a[0];
    function[(*stack_p)++]=num;
    (*i)--;
}

void judge_alpha(signed char function[],signed char *stack_p,
                 signed char *math_sign, signed char *math_pos,signed char *i)
{
    signed char k=0;
    k=*i;//kָ��ǰi��λ�ã���Ӧ�ñ�

    if(function[k]=='x')//�����δ֪��x����ջ��ֱ�ӷ���
    {
        function[(*stack_p)++]=-1;
        return ;
    }

    if( function[*i]=='s'&&function[(*i)+1]=='q')//Ӧ�Ը��ŵ����
        function[*i]='S';

    while( function[(*i)+1]!='(')
        (*i)++ ;//��ʱiӦָ�����������ŵ�ǰһ����ĸ

    (*math_pos)=(*i);
    while( function[(*math_pos)]!=')')
        (*math_pos)++;
//    (*math_pos)= (*math_pos)-4-*stack_temp_p;
    (*math_pos)= (*math_pos)-(*i)+(*stack_p)-2;

    switch(function[k])
    {
    case 'a'://abs
        (*math_sign)=-2;
        break;
    case 's'://sin
        (*math_sign)=-3;
        break;
    case 'c'://cos
        (*math_sign)=-4;
        break;
    case 't'://tan
        (*math_sign)=-5;
        break;
    case 'e'://exp
        (*math_sign)=-6;
        break;
    case 'l'://ln
    {
        (*math_sign)=-7;
        //  (*math_pos)++;
    }
    break;
    case 'S'://sqrt
    {
        (*math_sign)=-8;
        // (*math_pos)--;
    }
    break;
    }
}

void	get_polish_notation(signed char function[],signed char *function_position)
{
    signed char i;
    signed char stack_p=0;
    signed char stack_temp[7];//������������������
    signed char stack_temp_p=0;
    signed char math_sign;//��ѧ�����ı�־
    signed char math_pos=-1;//��ѧ������λ��

    for(i=0; i<(*function_position); i++)
    {

        if(stack_p==math_pos)
        {
            function[stack_p++]=(math_sign);
            i--;
            continue;
        }

        if('('<=function[i]&&function[i]<='/')
            judge_signature(function, &stack_p,stack_temp, &stack_temp_p, &i);//����

        else if('0'<=function[i]&&function[i]<='9')
            judge_number(function, function_position, &stack_p, &i);//����

        else if('a'<=function[i]&&function[i]<='z')
            judge_alpha(function, &stack_p, &math_sign, &math_pos, &i);//��ĸ

    }

//		  if(stack_p==math_pos)//��ѧ�������������
//            function[stack_p++]=(math_sign);

    // stack_temp_p--;
    while(stack_temp_p)//��ʣ�µ��������ջ
    {
        function[stack_p++]=stack_temp[stack_temp_p-1];
        stack_temp_p--;
    }


    *function_position=stack_p;//�����õĺ�̱��ʽ�ĳ���ˢ��һ�£�
}


float calculate_y(signed char function[],signed char function_position,float x)
{
    float stack[7];
    signed char stack_p=0,i;

    for(i=0; i<function_position; i++)
    {
        switch(function[i])
        {
        case -1:
            stack[stack_p++]=x;//����x
            break;
        case -2://�����Ǻ���
            stack[stack_p-1]=fabs(stack[stack_p-1]);
            break;
        case -3:
            stack[stack_p-1]=sin(stack[stack_p-1]);
            break;
        case -4:
            stack[stack_p-1]=cos(stack[stack_p-1]);
            break;
        case -5:
            stack[stack_p-1]=tan(stack[stack_p-1]);
            break;
        case -6:
            stack[stack_p-1]=exp(stack[stack_p-1]);
            break;
        case -7:
            stack[stack_p-1]=log(stack[stack_p-1]);
            break;
        case -8:
            stack[stack_p-1]=sqrt(stack[stack_p-1]);
            break;
        case -9://�����������
            stack[stack_p-2]=stack[stack_p-2]+stack[stack_p-1];
            stack_p--;
            break;
        case -10:
            stack[stack_p-2]=stack[stack_p-2]-stack[stack_p-1];
            stack_p--;
            break;
        case -11:
            stack[stack_p-2]=stack[stack_p-2]*stack[stack_p-1];
            stack_p--;
            break;
        case -12:
            stack[stack_p-2]=stack[stack_p-2]/stack[stack_p-1];
            stack_p--;
            break;
        default:
            stack[stack_p++]=function[i];
            break;
        }
    }
    return stack[0];
}



void blank()
{
    unsigned char i,j;
    for(i=0; i<8; i++)
    {
        Write_IIC_Command(0xb0+i); //10110000 | y//����ҳѰַ 1 0 1 1 A2 A1 A0
        Write_IIC_Command(0x02);//00000010  �����е�ַ�ĵ���λ
        Write_IIC_Command(0x10);//00010000  �����е�ַ�ĸ���λ
        for(j=0; j<128; j++)
        {
            Write_IIC_Data(0x00);
        }
    }
}


void draw_xy()//���������ᣬx=31(0001 1111)��y=63(0011 1111)
{
    unsigned char i;
    char a,a1,a2,b;
    a=(31+M*10);//aȷ��x���yֵ
    a1=7-a/8;//a1ȷ��x���ڵڼ�ҳ
    a2=0x01;//a2ȷ���ڸ�ҳӦ��д��ʲô����
    a2<<=(7-a%8);

    Write_IIC_Command(0xb0+a1); //����x��
    Write_IIC_Command(0x00);
    Write_IIC_Command(0x10);
    for(i=0; i<128; i++)
    {
        Write_IIC_Data(a2);
    }

    //����y��
    Delay_1ms(1);
    b=63-10*N;
    b>>=4;
    b=(b&0x0F)|0x10;
    for(i=0; i<8; i++)
    {
        Write_IIC_Command(0xb0+i);
        Write_IIC_Command(0x0F&(63-10*N));//������8λ

        Write_IIC_Command(b);//������8λ
        Write_IIC_Data(0xFF);
    }
}

void show_oled(signed char function[],signed char function_position,char choice)
{
    float x;
    int	y;
    char a,y1;
    char i=0x00,j=0x10;
    char ylow,yhigh;
    char x_asix_y;

    switch(choice)
    {
    case 0:
        M=0;
        N=0;
				Z=1;
        break;//default
    case 1:
        M-=1;
        break;//up
    case 2:
        N-=1;
        break;//left
    case 3:
        M+=1;
        break;//down
    case 4:
        N+=1;
        break;//right
		 case 5:
        Z/=1.5;//bigger
        break;
		 case 6:
        Z*=1.5;
        break;//smaller
    }
//�Ŵ�,Z��С

    Initial_M096128x64_ssd1306();
    Delay_1ms(5);
    blank();
    draw_xy();


    x_asix_y=(31+10*M);//�Ŵ�Ҫ�������᲻�䣬ͼ�������������
    ylow=(x_asix_y-x_asix_y%8);
    yhigh=ylow+7;

    for(x=(-6.2+N)*Z; x<(6.5+N)*Z; x=x+0.1*Z)//��Ϊ�Ŵ������Ա�����ȡֵ��Χ��С
    {
        y=(calculate_y(function,function_position,x)*10)/Z+x_asix_y;
			
        if(y<64&&y>=0)//��ͨ�ĺ���ֵ
        {
            y1=7-(char)(y/8);
            a=0x01;
            a<<=(7-(char)y%8);
            if(y>=ylow&&y<=yhigh)//����ֵ��x�ḽ��
            {
                char a1;//x����һ��ҳ�е�λ��
                a1=0x01;
                a1<<=(7-x_asix_y%8);
                a=a|a1;
            }
        }
        else//����ֵ������Ļ�����
        {
            i++;
            if(i==16)  {
                i=0;
                j++;
            }
            continue;
        }

        Write_IIC_Command(0xb0+y1);//ȷ����ʵ��λ��
        Write_IIC_Command(j);
        Write_IIC_Command(i++);
        if(i==16)  {
            i=0;
            j++;
        }

        if(x>0.05*Z&&x<0.15*Z) a=0xFF;//���Ϊx=0��Ҳ����y�ᣬȫ��

        Write_IIC_Data(a);
    }
    Delay_1ms(1);
    while(getkey()==0);
}



