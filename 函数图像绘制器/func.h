//#include <REGX52.H>
#include "LCD1602.h"
#include <math.h>

signed char getkey();

void Delay100ms(void);	//@11.0592MHz

void input_bit_0(signed char *a,signed char *i);

void input_bit_1(signed char *a,signed char *i);

void delete_bit(signed char *a,signed char *i,signed char function[],signed char *function_position);

void show_ASCII(signed char *a,signed char *i);

void confirm_bit(signed char *a, signed char *i,signed char function[],signed char *function_position);

void delete_function(signed char function[],signed char *function_position);

void	get_polish_notation(signed char function[],signed char *function_position);

void judge_signature(signed char function[],
                    signed char *stack_p,
                     signed char stack_temp[], signed char *stack_temp_p,signed char *i);

void judge_number(signed char function[],signed char *function_position,
                 signed char *stack_p,
                 signed char *i);

void judge_alpha(signed char function[],signed char *stack_p,
                 signed char *math_sign, signed char *math_pos,signed char *i);
									
float calculate_y(signed char function[],signed char function_position,float x);
								 
void show_oled(signed char function[],signed char function_position,char choice);
									
void blank();
									
void draw_xy();
								 


