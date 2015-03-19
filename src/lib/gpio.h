#ifndef GPIO_H
#define GPIO_H

#ifdef RPI2
    #define GPIO_BASE  0x3F200000
    #define GPIO_FSEL0 0x3F200000
    #define GPIO_FSEL1 0x3F200004
    #define GPIO_FSEL2 0x3F200008
    #define GPIO_FSEL3 0x3F20000C
    #define GPIO_FSEL4 0x3F200010
    #define GPIO_FSEL5 0x3F200014
    #define GPIO_SET0  0x3F20001C
    #define GPIO_SET1  0x3F000020
    #define GPIO_CLR0  0x3F200028
    #define GPIO_CLR1  0x3F20002C
    #define GPIO_LEV0  0x3F200034
    #define GPIO_LEV1  0x3F200038
#else
    #define GPIO_BASE  0x20200000
    #define GPIO_FSEL0 0x20200000
    #define GPIO_FSEL1 0x20200004
    #define GPIO_FSEL2 0x20200008
    #define GPIO_FSEL3 0x2020000C
    #define GPIO_FSEL4 0x20200010
    #define GPIO_FSEL5 0x20200014
    #define GPIO_SET0  0x2020001C
    #define GPIO_SET1  0x20000020
    #define GPIO_CLR0  0x20200028
    #define GPIO_CLR1  0x2020002C
    #define GPIO_LEV0  0x20200034
    #define GPIO_LEV1  0x20200038
#endif

#define GPIO_INPUT (char)(0)
#define GPIO_OUTPUT (char)(1)
#define GPIO_LOW (char)(0)
#define GPIO_HIGH (char)(1)
#define GPIO_ERROR (char)(127)

void gpio_pinMode(int pin, char mode);
void gpio_digitalWrite(int pin, char value);
char gpio_digitalRead(int pin);

#endif