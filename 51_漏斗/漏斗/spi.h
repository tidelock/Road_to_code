#ifndef __SPI_H_
#define __SPI_H_

#define CS P22
#define MOSI P23
#define MISO P24
#define SCL P25

void spi_init();

void spi_start();

void spi_stop();

unsigned char spi_exchangebyte(unsigned char byte);

#endif
