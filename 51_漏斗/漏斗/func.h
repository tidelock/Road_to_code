#ifndef __FUNC_H_
#define __FUNC_H_

typedef struct a
{
    char left : 5;
    char mid : 5;
    char right : 5;
    char exist : 1;
} light;

#define HC595_din P20
#define HC595_clk P21
#define HC595_storage P26
#define HC595_en P27

void init();

void IO_init();

void get_rand_array();

void frame();

void next_direction();

void show_light();

void time_init();

#endif