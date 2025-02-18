#include <STC8H.H>
#include "func.h"
#include "stdlib.h"
#include "LIS3DH.h"
#include "spi.h"

light x[27] = {0};
extern char direction;
int clk1=0,clk2=0,clk3;
idata char rand_array[26];

void init()
{
    char i;

    // 以下是配置IO口的模式
    IO_init();

    // 以下是SPI通信的初始化
    spi_init();

    // 以下是陀螺仪的初始化
    lis3dh_init();

    // 以下是配置定时器0方式0的中断
    time_init();

    // 以下是沙子的初始化位置
    for (i = 0; i < 12; i++) // 有沙子的部分
        x[i].exist = 1;
    for (i = 12; i < 26; i++) // 没有沙子的部分
        x[i].exist = 0;
    x[26].exist = 1; // 表示沙漏的边缘

    // 以下是获得随机顺序的数列
    for (i = 0; i < 26; i++)
        rand_array[i] = i;

    // 以下是配置ADC转换，从不稳定的引脚读出产生随机数的种子
    ADCTIM = 0x3F;
    ADCCFG = 0x0F;
    ADC_CONTR = 0x80;
}

void get_rand_array()
{
    char i;
    char num, temp;
    for (i = 0; i < 26; i++)
    {
        ADC_CONTR |= 0x40;
        while (!ADC_CONTR & 0x20);
        ADC_CONTR &= ~0x20;
        srand(clk3);
        num = rand() % 26;
        temp = rand_array[num];
        rand_array[num] = rand_array[i];
        rand_array[i] = temp;
    }
}

void IO_init() // IO口均配置成双向口模式
{
    P_SW2 |= 0x80;
    P0M0 = 0x00;
    P0M1 = 0x00;
    P1M0 = 0x00;
    P1M1 = 0x01;
    P2M0 = 0x00;
    P2M1 = 0x00;
    P3M0 = 0x00;
    P3M1 = 0x00;
}

void frame()
{
    switch (direction)
    {
    case Down:
    {
        x[0].left = 3;x[0].mid = 7;x[0].right = 4;
        x[1].left = 4;x[1].mid = 8;x[1].right = 5;
        x[2].left = 5;x[2].mid = 9;x[2].right = 6;
        x[3].left = 26;x[3].mid = 26;x[3].right = 7;
        x[4].left = 7;x[4].mid = 10;x[4].right = 8;
        x[5].left = 8;x[5].mid = 11;x[5].right = 9;
        x[6].left = 9;x[6].mid = 26;x[6].right = 26;
        x[7].left = 26;x[7].mid = 26;x[7].right = 10;
        x[8].left = 10;x[8].mid = 12;x[8].right = 11;
        x[9].left = 11;x[9].mid = 26;x[9].right = 26;
        x[10].left = 26;x[10].mid = 26;x[10].right = 12;
        x[11].left = 12;x[11].mid = 26;x[11].right = 26;
        x[12].left = 26;x[12].mid = 13;x[12].right = 26;
        x[13].left = 14;x[13].mid = 17;x[13].right = 15;
        x[14].left = 16;x[14].mid = 20;x[14].right = 17;
        x[15].left = 17;x[15].mid = 21;x[15].right = 18;
        x[16].left = 19;x[16].mid = 23;x[16].right = 20;
        x[17].left = 20;x[17].mid = 24;x[17].right = 21;
        x[18].left = 21;x[18].mid = 25;x[18].right = 22;
        x[19].left = 26;x[19].mid = 26;x[19].right = 23;
        x[20].left = 23;x[20].mid = 26;x[20].right = 24;
        x[21].left = 24;x[21].mid = 26;x[21].right = 25;
        x[22].left = 25;x[22].mid = 26;x[22].right = 26;
        x[23].left = 26;x[23].mid = 26;x[23].right = 26;
        x[24].left = 26;x[24].mid = 26;x[24].right = 26;
        x[25].left = 26;x[25].mid = 26;x[25].right = 26;
    }
    break;
    case Up:
    {
        x[0].left = 26;x[0].mid = 26;x[0].right = 26;
        x[1].left = 26;x[1].mid = 26;x[1].right = 26;
        x[2].left = 26;x[2].mid = 26;x[2].right = 26;
        x[3].left = 0;x[3].mid = 26;x[3].right = 26;
        x[4].left = 1;x[4].mid = 26;x[4].right = 0;
        x[5].left = 2;x[5].mid = 26;x[5].right = 1;
        x[6].left = 26;x[6].mid = 26;x[6].right = 2;
        x[7].left = 4;x[7].mid = 0;x[7].right = 3;
        x[8].left = 5;x[8].mid = 1;x[8].right = 4;
        x[9].left = 6;x[9].mid = 2;x[9].right = 5;
        x[10].left = 8;x[10].mid = 4;x[10].right = 7;
        x[11].left = 9;x[11].mid = 5;x[11].right = 8;
        x[12].left = 11;x[12].mid = 8;x[12].right = 10;
        x[13].left = 26;x[13].mid = 12;x[13].right = 26;
        x[14].left = 13;x[14].mid = 26;x[14].right = 26;
        x[15].left = 26;x[15].mid = 26;x[15].right = 13;
        x[16].left = 14;x[16].mid = 26;x[16].right = 26;
        x[17].left = 15;x[17].mid = 13;x[17].right = 14;
        x[18].left = 26;x[18].mid = 26;x[18].right = 15;
        x[19].left = 16;x[19].mid = 26;x[19].right = 26;
        x[20].left = 17;x[20].mid = 14;x[20].right = 16;
        x[21].left = 18;x[21].mid = 15;x[21].right = 17;
        x[22].left = 26;x[22].mid = 26;x[22].right = 18;
        x[23].left = 20;x[23].mid = 16;x[23].right = 19;
        x[24].left = 21;x[24].mid = 17;x[24].right = 20;
        x[25].left = 22;x[25].mid = 18;x[25].right = 21;
    }
        break;
    case Left:
    {
        x[0].left = 26;x[0].mid = 26;x[0].right = 3;
        x[1].left = 26;x[1].mid = 0;x[1].right = 4;
        x[2].left = 26;x[2].mid = 1;x[2].right = 5;
        x[3].left = 26;x[3].mid = 26;x[3].right = 26;
        x[4].left = 0;x[4].mid = 3;x[4].right = 7;
        x[5].left = 1;x[5].mid = 4;x[5].right = 8;
        x[6].left = 2;x[6].mid = 5;x[6].right = 9;
        x[7].left = 3;x[7].mid = 26;x[7].right = 26;
        x[8].left = 4;x[8].mid = 7;x[8].right = 10;
        x[9].left = 5;x[9].mid = 8;x[9].right = 11;
        x[10].left = 7;x[10].mid = 26;x[10].right = 26;
        x[11].left = 8;x[11].mid = 10;x[11].right = 12;
        x[12].left = 10;x[12].mid = 26;x[12].right = 26;
        x[13].left = 26;x[13].mid = 26;x[13].right = 14;
        x[14].left = 26;x[14].mid = 26;x[14].right = 16;
        x[15].left = 13;x[15].mid = 14;x[15].right = 17;
        x[16].left = 26;x[16].mid = 26;x[16].right = 19;
        x[17].left = 14;x[17].mid = 16;x[17].right = 20;
        x[18].left = 15;x[18].mid = 17;x[18].right = 21;
        x[19].left = 26;x[19].mid = 26;x[19].right = 26;
        x[20].left = 16;x[20].mid = 19;x[20].right = 23;
        x[21].left = 17;x[21].mid = 20;x[21].right = 24;
        x[22].left = 18;x[22].mid = 21;x[22].right = 25;
        x[23].left = 19;x[23].mid = 26;x[23].right = 26;
        x[24].left = 20;x[24].mid = 23;x[24].right = 26;
        x[25].left = 21;x[25].mid = 24;x[25].right = 26;
    }
        break;
    case Right:
    {
        x[0].left = 4;x[0].mid = 1;x[0].right = 26;
        x[1].left = 5;x[1].mid = 2;x[1].right = 26;
        x[2].left = 6;x[2].mid = 26;x[2].right = 26;
        x[3].left = 7;x[3].mid = 4;x[3].right = 0;
        x[4].left = 8;x[4].mid = 5;x[4].right = 1;
        x[5].left = 9;x[5].mid = 6;x[5].right = 2;
        x[6].left = 26;x[6].mid = 26;x[6].right = 26;
        x[7].left = 10;x[7].mid = 8;x[7].right = 4;
        x[8].left = 11;x[8].mid = 9;x[8].right = 5;
        x[9].left = 26;x[9].mid = 26;x[9].right = 6;
        x[10].left = 12;x[10].mid = 11;x[10].right = 8;
        x[11].left = 26;x[11].mid = 26;x[11].right = 9;
        x[12].left = 26;x[12].mid = 26;x[12].right = 11;
        x[13].left = 15;x[13].mid = 26;x[13].right = 26;
        x[14].left = 17;x[14].mid = 15;x[14].right = 13;
        x[15].left = 18;x[15].mid = 26;x[15].right = 26;
        x[16].left = 20;x[16].mid = 17;x[16].right = 14;
        x[17].left = 21;x[17].mid = 18;x[17].right = 15;
        x[18].left = 22;x[18].mid = 26;x[18].right = 26;
        x[19].left = 23;x[19].mid = 20;x[19].right = 16;
        x[20].left = 24;x[20].mid = 21;x[20].right = 17;
        x[21].left = 25;x[21].mid = 22;x[21].right = 18;
        x[22].left = 26;x[22].mid = 26;x[22].right = 26;
        x[23].left = 26;x[23].mid = 24;x[23].right = 20;
        x[24].left = 26;x[24].mid = 25;x[24].right = 21;
        x[25].left = 26;x[25].mid = 26;x[25].right = 22;
    }
        break;
    }
}

void next_direction()
{
    char i1,i;
    char a;
	get_rand_array();
    for (i1 = 0; i1 <26; i1++)
    {
        i=rand_array[i1];
        if (!x[i].exist)
            continue;

        a = x[x[i].left].exist * 4 + x[x[i].mid].exist * 2 + x[x[i].right].exist;
        x[i].exist = 0;
        switch (a)
        {
        case 0: // 000
            x[x[i].mid].exist = 1;
            break;
        case 1: // 001
            x[x[i].left].exist = 1;
            break;
        case 2: // 010
            ADC_CONTR |= 0x40;
            while (!ADC_CONTR & 0x20);
            ADC_CONTR &= ~0x20;
            srand(clk3);
            rand() % 2 ? (x[x[i].left].exist = 1) : (x[x[i].right].exist = 1);
            break;
        case 3: // 011
            x[x[i].left].exist = 1;
            break;
        case 4: // 100
            x[x[i].right].exist = 1;
            break;
        case 5: // 101
            x[i].exist = 1;
            break;
        case 6: // 110
            x[x[i].right].exist = 1;
            break;
        case 7: // 111
            x[i].exist = 1;
            break;

        default:
            break;
        }
    }
}

void show_light() // 用4个74HC595够了吧
{
    char i;
    HC595_en = 1;
    HC595_storage = 0;
    for (i = 25; i > -1; i--) // clk上升沿移位，下降沿不变
    {
        HC595_clk = 0;
        x[i].exist ? (HC595_din = 1) : (HC595_din = 0);
        HC595_clk = 1;
    }
    HC595_storage = 1;
    HC595_en = 0;
}

void time_init()
{
    TMOD = 0x00;//使用定时器的模式0，16位自动重载
    TH0=0xFC;
    TL0=0x66;
    TR0=1;
    ET0=1;
    EA=1;
}

void time_IR() interrupt 1 // 使用定时器0  1ms进入一次(11.0592)
{
    int clk2_end;
    clk1++;
    clk2++;
    clk3++;
    if (clk1 == 20) // 每0.1秒刷新
    {
        frame();
        next_direction();
        clk1 = 0;
    }

    clk2_end = 500; // 一分钟
    // if (!P1 ^ 0)
    //     clk2_end = 2500; // 五分钟
    // if (!P1 ^ 1)
    //     clk2_end = 5000; // 十分钟
    // if (!P1 ^ 2)
    //     clk2_end = 7500; // 十五分钟

    if (clk2 == clk2_end)     // 每1秒瓶颈出掉落沙子
    {
        clk2 = 0;
        if (x[12].exist && x[12].mid == 13)
        {
            x[12].exist = 0;
            x[13].exist = 1;
        }
        if (x[13].exist && x[13].mid == 12)
        {
            x[12].exist = 1;
            x[13].exist = 0;
        }
    }
    show_light();
}