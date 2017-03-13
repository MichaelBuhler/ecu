#ifndef SERIAL_H
#define SERIAL_H

#include "char_buffer.h"

typedef struct serial_t {
    unsigned char rx_pin;
    unsigned char tx_pin;
    unsigned char us;
    char_buffer_t rx_buffer;
    char_buffer_t tx_buffer;
} serial_t;

void serial_init (serial_t*, unsigned char, unsigned char);
void serial_begin (serial_t*, unsigned long);
void serial_write (serial_t*, unsigned char);
void serial_loop (serial_t*, unsigned long);

#endif