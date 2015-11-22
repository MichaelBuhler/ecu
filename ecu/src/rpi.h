#ifndef RPI_H
#define RPI_H

#define PERIPHERAL_BASE 0x3F000000
#define ONBOARD_LED 47

void noop();
void put32( unsigned long, unsigned long );
unsigned long get32( unsigned long );

#endif