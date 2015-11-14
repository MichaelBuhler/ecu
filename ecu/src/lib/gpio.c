#include "gpio.h"

void put32 ( unsigned int, unsigned int );
unsigned int get32 ( unsigned int );

void gpio_mode( unsigned int pin, unsigned int mode) {
    unsigned int fsel = 0;
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

