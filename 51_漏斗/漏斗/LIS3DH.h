#ifndef __LIS3DH_H_
#define __LIS3DH_H_

#define XL 0x28
#define XH 0x29
#define YL 0x2A
#define YH 0x2B
#define ZL 0x2C
#define ZH 0x2D

#define Down 0
#define Up 1
#define Left 2
#define Right 3
extern char direction;

typedef struct b
{
    signed int x_axis;
    signed int y_axis;
    signed int z_axis;
}lis3dh;

void lis3dh_init();

void get_xyz();

void get_direction();







#endif
