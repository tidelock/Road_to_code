#include <STC8H.H>
#include "spi.h"

void spi_init()
{
    CS = 1;
    SCL = 1;
    MOSI = 0;
    MISO = 0;
}

void spi_start()
{
    CS = 0;
}

void spi_stop()
{
    CS = 1;
}

unsigned char spi_exchangebyte(unsigned char byte)
{
    char i;
    char temp = 0;
    spi_start();
    for (i = 0; i < 8; i++)
    {
        SCL = 0;
        MOSI = byte & (0x80 >> i);
        if (MISO)
            temp |= (0x80 >> i);
        SCL = 1;
    }
    spi_stop();
    return temp;
}
