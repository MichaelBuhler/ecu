#ifndef ECU_H
#define ECU_H

#ifdef RPI2
    #define ONBOARD_LED 47
#else
    #define ONBOARD_LED 16
#endif

void noop ( unsigned int );
void put32 ( unsigned int, unsigned int );
unsigned int get32 ( unsigned int );
void enable_irq();

#endif
