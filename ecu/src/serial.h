#ifndef SERIAL_H
#define SERIAL_H

typedef struct serial_t {
    unsigned char rx;
    unsigned char tx;
    unsigned char us;
} serial_t;

void serial_init (serial_t*, unsigned char, unsigned char);
void serial_begin (serial_t*, unsigned long);
void serial_write (serial_t*, unsigned char);

#endif