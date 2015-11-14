#include "gpio.h"
#include "ecu.h"

void gpio_write( unsigned int pin, unsigned int value) {
    if ( value == 0 ) {
        if ( pin < 32 ) {
            put32( GPIO_CLR0, 1<<pin );
        } else {
            put32( GPIO_CLR1, 1<<(pin%32) );
        }
    }
    if ( value == 1 ) {
        if ( pin < 32 ) {
            put32( GPIO_SET0, 1<<pin );
        } else {
            put32( GPIO_SET1, 1<<(pin%32) );
        }
    }
}

unsigned int gpio_read( unsigned int pin ) {
    unsigned int lev;
    if ( pin < 32 ) {
        lev = get32( GPIO_LEV0 );
    } else {
        lev = get32( GPIO_LEV1 );
    }
    lev &= 1<<(pin%32);
    if ( lev > 0 ) return 1;
    return 0;
}

