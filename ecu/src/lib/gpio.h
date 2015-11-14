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
    #define GPIO_EDS0  0x3F200040
    #define GPIO_EDS1  0x3F200044
    #define GPIO_REN0  0x3F20004C
    #define GPIO_REN1  0x3F200050
    #define GPIO_FEN0  0x3F200058
    #define GPIO_FEN1  0x3F20005C
    #define GPIO_HEN0  0x3F200064
    #define GPIO_HEN1  0x3F200068
    #define GPIO_LEN1  0x3F200070
    #define GPIO_LEN0  0x3F200074
    #define GPIO_AREN0 0x3F20007C
    #define GPIO_AREN1 0x3F200080
    #define GPIO_AFEN0 0x3F200088
    #define GPIO_AFEN1 0x3F20008C
    #define GPIO_PUD   0x3F200094
    #define GPIO_PUDCLK0 0x3F200098
    #define GPIO_PUDCLK1 0x3F20009C
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
    #define GPIO_EDS0  0x20200040
    #define GPIO_EDS1  0x20200044
    #define GPIO_REN0  0x2020004C
    #define GPIO_REN1  0x20200050
    #define GPIO_FEN0  0x20200058
    #define GPIO_FEN1  0x2020005C
    #define GPIO_HEN0  0x20200064
    #define GPIO_HEN1  0x20200068
    #define GPIO_LEN1  0x20200070
    #define GPIO_LEN0  0x20200074
    #define GPIO_AREN0 0x2020007C
    #define GPIO_AREN1 0x20200080
    #define GPIO_AFEN0 0x20200088
    #define GPIO_AFEN1 0x2020008C
    #define GPIO_PUD   0x20200094
    #define GPIO_PUDCLK0 0x20200098
    #define GPIO_PUDCLK1 0x2020009C
#endif

#define GPIO_INPUT (char)(0)
#define GPIO_OUTPUT (char)(1)
#define GPIO_LOW (char)(0)
#define GPIO_HIGH (char)(1)
#define GPIO_ERROR (char)(127)

void gpio_mode(int pin, char mode);
char gpio_read(int pin);
void gpio_write(int pin, char value);

#endif