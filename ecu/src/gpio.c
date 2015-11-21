#include "gpio.h"

void gpio_mode( unsigned char pin, unsigned char mode) {
    unsigned long fsel = 0;
    if ( pin < 10 ) {
        fsel = get32( GPIO_FSEL0 );
    } else if ( pin < 20 ) {
        fsel = get32( GPIO_FSEL1 );
    } else if ( pin < 30 ) {
        fsel = get32( GPIO_FSEL2 );
    } else if ( pin < 40 ) {
        fsel = get32( GPIO_FSEL3 );
    } else if ( pin < 50 ) {
        fsel = get32( GPIO_FSEL4 );
    } else if ( pin < 54 ) {
        fsel = get32( GPIO_FSEL5 );
    }
    fsel &= ~(7<<((pin%10)*3));
    fsel |= mode<<((pin%10)*3);
    if ( pin < 10 ) {
        put32( GPIO_FSEL0, fsel );
    } else if ( pin < 20 ) {
        put32( GPIO_FSEL1, fsel );
    } else if ( pin < 30 ) {
        put32( GPIO_FSEL2, fsel );
    } else if ( pin < 40 ) {
        put32( GPIO_FSEL3, fsel );
    } else if ( pin < 50 ) {
        put32( GPIO_FSEL4, fsel );
    } else if ( pin < 54 ) {
        put32( GPIO_FSEL5, fsel );
    }
}

void gpio_write( unsigned char pin, unsigned char value) {
    if ( value == GPIO_LOW ) {
        if ( pin < 32 ) {
            put32( GPIO_CLR0, 1<<pin );
        } else {
            put32( GPIO_CLR1, 1<<(pin%32) );
        }
    }
    if ( value == GPIO_HIGH ) {
        if ( pin < 32 ) {
            put32( GPIO_SET0, 1<<pin );
        } else {
            put32( GPIO_SET1, 1<<(pin%32) );
        }
    }
}

unsigned char gpio_read( unsigned char pin ) {
    unsigned char lev;
    if ( pin < 32 ) {
        lev = get32( GPIO_LEV0 );
    } else {
        lev = get32( GPIO_LEV1 );
    }
    lev &= 1<<(pin%32);
    if ( lev ) return GPIO_HIGH;
    return GPIO_LOW;
}
