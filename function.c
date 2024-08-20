#include "function.h"

void Init_a(char a[][41]) // 二维数组的初始化,a[21][41]对应的是a[y][x]
{
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 41; j++)
            a[i][j] = 'K';

    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 40; j++)
        {
            a[i][0] = a[i][39] = a[0][j] = a[20][j] = 'B';
            a[i][40] = 'E';
        }
    food = 0;
}

void Init_snack(snack *s_first) // 蛇的初始化，刚开始的蛇身只有两个
{
    s_first->x = 15;
    s_first->y = 10;
    s_first->direction = 'r';
    s_first->next = (snack *)malloc(sizeof(snack));
    s_first->next->x = 14;
    s_first->next->y = 10;
    s_first->next->direction = 'r';
    s_first->next->next = NULL;

    length=2;
}

void show_a(char a[][41]) // 打印数组，对于不同的char字符，打印不同的东西
{
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 41; j++)
            switch (a[i][j])
            {
            case 'B':

                printf("■");
                break;
            case 'F':
                printf("▼");
                break;
            case 'S':

                printf("●");
                break;
            case 'E':
                printf("\n");
                break;
            default:
                printf(" ");
                break;
            }
            printf("\nlength:  %d\n",length);
}

void sleep(snack *s_first) // 时间间隔并同时接受键盘数据
{
    char ch, contrary;
    for (int i = 0; i < 5000; i++) // 时间延迟
        for (int j = 0; j < 30000; j++)
            ;
    if (_kbhit()) // 在延迟的过程中有没有按键输入
    {
        ch = getch();

        if (ch == '8' || ch == 'w')
            ch = '8';
        else if (ch == '4' || ch == 'a')
            ch = '4';
        else if (ch == '6' || ch == 'd')
            ch = '6';
        else if (ch == '2' || ch == 's')
            ch = '2';
        else
            ;

        switch (s_first->direction) // 输入的方向不能与蛇前进的方向相反
        {
        case 'r':
            contrary = '4';
            break;
        case 'l':
            contrary = '6';
            break;
        case 'u':
            contrary = '2';
            break;
        case 'd':
            contrary = '8';
            break;
        }
        if (ch != contrary) // 下一步蛇前进方向就是输入方向
            switch (ch)
            {
            case '0':
                exit(0);
                break;
            case '8':
                s_first->direction = 'u';
                break;
            case '4':
                s_first->direction = 'l';
                break;
            case '6':
                s_first->direction = 'r';
                break;
            case '2':
                s_first->direction = 'd';
                break;
            }
        system("cls");
    }
}

void move_s(snack *s, char a[][41]) // 蛇进行移动
{
    snack *temp = (snack *)malloc(sizeof(snack));
    snack *newnode = (snack *)malloc(sizeof(snack));
    temp = s;

    newnode->x = s->x;
    newnode->y = s->y;
    newnode->direction = s->direction;

    if (s->next->next != NULL)
    {

        while (temp->next->next != NULL)
            temp = temp->next;
        a[temp->next->y][temp->next->x] = 'K';
        free(temp->next);
        temp->next = NULL;

        newnode->next = s->next;
    }
    else
    {
        a[s->next->y][s->next->x] = 'K';
        newnode->next = NULL;
    }
    s->next = newnode;

    switch (s->direction)
    {
    case 'r':
        s->x++;
        break;
    case 'l':
        s->x--;
        break;
    case 'u':
        s->y--;
        break;
    case 'd':
        s->y++;
        break;
    }
    a[s->y][s->x] = 'S';

    temp = s;
    while (temp != NULL)
    {
        a[temp->y][temp->x] = 'S';
        temp = temp->next;
    }

    // if (a[s->y][s->x] == 'B' || a[s->y][s->x] == 'S')
    // {
    //     printf("game over!\n");
    //     exit(0);
    // }
}

void get_rand_food(char a[][41]) // 产生随机食物
{
    int i;
    i = rand() % 722 + 1;
    while (a[1 + i / 38][1 + i % 38] != 'S' && food == 0)
    {
        a[1 + i / 38][1 + i % 38] = 'F';
        food = 1;
    }
}

void s_front(snack *s, char a[][41]) // 判定蛇前方是什么
{
    char ch;
    switch (s->direction)
    {
    case 'r':
        ch = a[s->y][s->x + 1];
        break;
    case 'l':
        ch = a[s->y][s->x - 1];
        break;
    case 'u':
        ch = a[s->y - 1][s->x];
        break;
    case 'd':
        ch = a[s->y + 1][s->x];
        break;
    }
    switch (ch)
    {
    case 'B':
    case 'S':
    {
        printf("game over\nexit\n");
        system("pause");
        exit(0);
    }
    break;
    case 'F':
    {
        food = 0;
        length++;
        snack *temp = (snack *)malloc(sizeof(snack));
        temp = s;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = (snack *)malloc(sizeof(snack));
        temp->next->x = temp->x;
        temp->next->y = temp->y;
        temp->next->direction = temp->direction;
        temp->next->next = NULL;

        switch (temp->direction)
        {
        case 'r':
            temp->next->x--;
            break;
        case 'l':
            temp->next->x++;
            break;
        case 'u':
            temp->next->y++;
            break;
        case 'd':
            temp->next->y--;
            break;
        }
        a[temp->next->y][temp->next->x] = 'S';
    }

    break;
    }
}
