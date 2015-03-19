#include "gpio.h"

void gpio_pinMode(int pin, char mode) {
    unsigned long *reg;
    if ( pin < 10 )
        reg = (unsigned long*)(GPIO_FSEL0);
    else if ( pin < 20 )
        reg = (unsigned long*)(GPIO_FSEL1);
    else if ( pin < 30 )
        reg = (unsigned long*)(GPIO_FSEL2);
    else if ( pin < 40 )
        reg = (unsigned long*)(GPIO_FSEL3);
    else if ( pin < 50 )
        reg = (unsigned long*)(GPIO_FSEL4);
    else if ( pin <= 53 )
        reg = (unsigned long*)(GPIO_FSEL5);
    else
        return;
    pin %= 10;
    pin *= 3;
    switch ( mode ) {
        case GPIO_INPUT:
            *reg &= ~(7<pin);
            break;
        case GPIO_OUTPUT:
            *reg &= ~(7<pin);
            *reg |= (1<<pin);
            break;
        default:
            return;
    }
}

void gpio_digitalWrite(int pin, char value) {
    unsigned long *reg;
    switch ( value ) {
        case GPIO_LOW:
            if ( pin < 32 )
                reg = (unsigned long*)(GPIO_CLR0);
            else if ( pin <= 53 )
                reg = (unsigned long*)(GPIO_CLR1);
            else
                return;
            break;
        case GPIO_HIGH:
            if ( pin < 32 )
                reg = (unsigned long*)(GPIO_SET0);
            else if ( pin <= 53 )
                reg = (unsigned long*)(GPIO_SET1);
            else
                return;
            break;
        default:
            return;
    }
    pin %= 32;
    *reg = (1<<pin);
}
