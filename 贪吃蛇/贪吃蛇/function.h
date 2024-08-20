#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Snack
{
    int x;
    int y;
    char direction;
    struct Snack *next;
} snack;

int food;
int length;

void Init_a(char a[][41]);

void show_a(char a[][41]);

void Init_snack(snack *s_first);

void sleep(snack *s_first);

void move_s(snack *s,char a[][41]);

void get_rand_food(char a[][41]);

void s_front(snack *s,char a[][41]);