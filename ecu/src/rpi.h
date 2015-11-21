#ifndef RPI_H
#define RPI_H

#ifdef RPI2
    #define PERIPHERAL_BASE 0x3F000000
    #define ONBOARD_LED 47
#else
    #define PERIPHERAL_BASE 0x20000000
    #define ONBOARD_LED 16
#endif

void noop ( unsigned int );
void put32 ( unsigned int, unsigned int );
unsigned int get32 ( unsigned int );

#endif