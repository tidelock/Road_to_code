#include "func.h"

signed char key;
signed char i=0;
signed char a=0;
signed char function[16]="2*sin(x*2)/x";//{0}
signed char function_position=12;
//限制：函数只能是十六个字符，数学函数不能嵌套，最多只有两个数学函数
//出现的数字不能是小数，没有指数函数

void main()
{
    LCD_Init();

	while(1)
    {
       while(( key=getkey())==0);
			
        switch(key)
        {
        case 1://输入位0
        {
            input_bit_0(&a, &i);
					
            break;
        }
        case 2://输入位1
        {
            input_bit_1(&a, &i);
            break;
        }
        case 3://删除位
        {
            delete_bit(&a, &i,function,&function_position);
            break;
        }
        case 4://确认ASCII并显示出值
        {
           	confirm_bit(&a, &i,function,&function_position);
            break;
        }
        case 5://删除函数表达式的字符
        {
					delete_function(function,&function_position);
					break;
				}
        case 7://计算函数值
        {
				get_polish_notation(function,&function_position);
				show_oled(function,function_position,0);	
				continue;
				}

        case 6://向上
        {
				show_oled(function,function_position,1);
					continue;
				}
        case 9://向左
        {
				show_oled(function,function_position,2);
					continue;
				}
        case 10://向下
        {
				show_oled(function,function_position,3);
					continue;
				}
        case 11://向右
        {
				show_oled(function,function_position,4);
					continue;
				}

        case 8://放大
        {
					show_oled(function,function_position,5);
					continue;
				}
        case 12://缩小
        {
					show_oled(function,function_position,6);
					continue;
				}
        }
       show_ASCII(&a,&i);
       Delay100ms();
    }

}