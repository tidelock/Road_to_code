#include "func.h"

signed char key;
signed char i=0;
signed char a=0;
signed char function[16]="2*sin(x*2)/x";//{0}
signed char function_position=12;
//���ƣ�����ֻ����ʮ�����ַ�����ѧ��������Ƕ�ף����ֻ��������ѧ����
//���ֵ����ֲ�����С����û��ָ������

void main()
{
    LCD_Init();

	while(1)
    {
       while(( key=getkey())==0);
			
        switch(key)
        {
        case 1://����λ0
        {
            input_bit_0(&a, &i);
					
            break;
        }
        case 2://����λ1
        {
            input_bit_1(&a, &i);
            break;
        }
        case 3://ɾ��λ
        {
            delete_bit(&a, &i,function,&function_position);
            break;
        }
        case 4://ȷ��ASCII����ʾ��ֵ
        {
           	confirm_bit(&a, &i,function,&function_position);
            break;
        }
        case 5://ɾ���������ʽ���ַ�
        {
					delete_function(function,&function_position);
					break;
				}
        case 7://���㺯��ֵ
        {
				get_polish_notation(function,&function_position);
				show_oled(function,function_position,0);	
				continue;
				}

        case 6://����
        {
				show_oled(function,function_position,1);
					continue;
				}
        case 9://����
        {
				show_oled(function,function_position,2);
					continue;
				}
        case 10://����
        {
				show_oled(function,function_position,3);
					continue;
				}
        case 11://����
        {
				show_oled(function,function_position,4);
					continue;
				}

        case 8://�Ŵ�
        {
					show_oled(function,function_position,5);
					continue;
				}
        case 12://��С
        {
					show_oled(function,function_position,6);
					continue;
				}
        }
       show_ASCII(&a,&i);
       Delay100ms();
    }

}