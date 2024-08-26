#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

int main()
{
    char a[21][41];
    char ch;
    srand((unsigned int)time(NULL));
    Init_a(a);
    snack *s_first = (snack *)malloc(sizeof(snack));//忘记释放空间了，可以自行编写释放的代码
    Init_snack(s_first);
    a[10][15] = a[10][14] = 'S';

    printf("这是一个贪吃蛇的小游戏\n");
    printf("请按8 4 6 2 或者W A S D 控制蛇移动的方向\n");
    printf("8: 向上\t2: 向下\t4: 向左\t6: 向右\n");
    printf("W: 向上\tS: 向下\tA: 向左\tD: 向右\n");
    printf("\n请按 0 退出游戏");
    printf("\n请按任意键开始\n");
    system("pause");
    system("cls");

    while (1)
    {
        get_rand_food(a);
        sleep(s_first);
        s_front(s_first, a);
        move_s(s_first, a);
        system("cls");
        show_a(a);
    }

    system("pause");
    return 0;
}
