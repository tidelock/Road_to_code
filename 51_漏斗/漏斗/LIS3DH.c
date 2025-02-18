#include <STC8H.H>
#include "LIS3DH.h"
#include "spi.h"

lis3dh lis;
char direction;

void lis3dh_init()
{
    spi_exchangebyte(0x20);//CTRL_REG0
    spi_exchangebyte(0x47);//50Hz
}

void get_xyz()
{
    //正常模式 十位输出
    spi_exchangebyte(XH | 0x80); // x轴高位地址，读操作，地址不递增
    lis.x_axis = ((signed int)spi_exchangebyte(0x00) << 8);
    spi_exchangebyte(XL | 0x80); // x轴低位地址，读操作，地址不递增
    lis.x_axis |= spi_exchangebyte(0x00);

    spi_exchangebyte(YH | 0x80); // y轴高位地址，读操作，地址不递增
    lis.y_axis = ((signed int)spi_exchangebyte(0x00) << 8);
    spi_exchangebyte(YL | 0x80); // y轴低位地址，读操作，地址不递增
    lis.y_axis |= spi_exchangebyte(0x00);

    spi_exchangebyte(ZH | 0x80); // z轴高位地址，读操作，地址不递增
    lis.z_axis = ((signed int)spi_exchangebyte(0x00) << 8);
    spi_exchangebyte(ZL | 0x80); // z轴低位地址，读操作，地址不递增
    lis.z_axis |= spi_exchangebyte(0x00);

    // 补码转换正负号   
    //-1 0000 0000 0000 0001 / 1111 1111 1111 1111 /0000 0000 0000 0001/1000 0000 0000 0001
    //-512 0000 0010 0000 0000/ 1111 1101 1111 1111 / 0000 0010 0000 0001 /
    if (lis.x_axis & 0x8000)
        lis.x_axis = (~lis.x_axis + 1) | 0x8000;
    if (lis.y_axis & 0x8000)
        lis.y_axis = (~lis.y_axis + 1) | 0x8000;
    if (lis.z_axis & 0x8000)
        lis.z_axis = (~lis.z_axis + 1) | 0x8000;
}

void get_direction()/////////存疑
{
    get_xyz();
    if (lis.x_axis < -128)
        direction = Down;
    if (lis.x_axis > 128)
        direction = Up;
    if (lis.y_axis < -128)
        direction = Left;
    if (lis.y_axis > 128)
        direction = Right;
}