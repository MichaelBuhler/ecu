#ifndef GPIO_H
#define GPIO_H

#include "rpi.h"

#define GPIO_BASE PERIPHERAL_BASE+0x00200000

#define GPIO_FSEL0 GPIO_BASE
#define GPIO_FSEL1 GPIO_BASE+0x04
#define GPIO_FSEL2 GPIO_BASE+0x08
#define GPIO_FSEL3 GPIO_BASE+0x0C
#define GPIO_FSEL4 GPIO_BASE+0x10
#define GPIO_FSEL5 GPIO_BASE+0x14
#define GPIO_SET0 GPIO_BASE+0x1C
#define GPIO_SET1 GPIO_BASE+0x20
#define GPIO_CLR0 GPIO_BASE+0x28
#define GPIO_CLR1 GPIO_BASE+0x2C
#define GPIO_LEV0 GPIO_BASE+0x34
#define GPIO_LEV1 GPIO_BASE+0x38

#define GPIO_INPUT 0
#define GPIO_OUTPUT 1

#define GPIO_LOW 0
#define GPIO_HIGH 1

void gpio_mode (unsigned char, unsigned char);
void gpio_write (unsigned char, unsigned char);
unsigned char gpio_read (unsigned char);

#endif