#include "rpi.h"

extern void _store(unsigned long* r0, unsigned long r1);

volatile unsigned int timer = 0;

void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags ) {
    unsigned long* gpfsel0 = (unsigned long*)GPFSEL0;
    unsigned long* gpclr0  = (unsigned long*)GPCLR0;
    unsigned long* gpset0  = (unsigned long*)GPSET0;
    *gpfsel0 |= (1<<12);
    while (1) {
        _store(gpclr0,(1<<4));
        for ( timer = 0 ; timer < 500000 ; timer++ ) {}
        _store(gpset0,(1<<4));
        for ( timer = 0 ; timer < 500000 ; timer++ ) {}
    }
}

void exit(int code) {
    while (1) {}
}
