#include <string.h>
#include "serial.h"
#include "rpi.h"
#include "gpio.h"
#include "systimer.h"
#include "char_buffer.h"

void serial_init (serial_t *serial, unsigned char rx_pin, unsigned char tx_pin) {
    serial->rx_pin = rx_pin;
    serial->tx_pin = tx_pin;
    char_buffer_init(&(serial->rx_buffer));
    char_buffer_init(&(serial->tx_buffer));
    char_buffer_writeln(&(serial->tx_buffer), "hello world");
    gpio_mode(rx_pin, GPIO_INPUT);
    gpio_mode(tx_pin, GPIO_OUTPUT);
}

void serial_begin (serial_t *serial, unsigned long baud_rate) {
    serial->us = 1000000 / baud_rate;
    gpio_write(serial->tx_pin, GPIO_HIGH);
    delay(serial->us);
}

void serial_write (serial_t *serial, unsigned char b) {
    gpio_write(serial->tx_pin, GPIO_LOW);
    delay(serial->us);
    
    unsigned char mask;
    for ( mask = 1; mask; mask<<=1 ) {
        if ( b&mask ) {
            gpio_write(serial->tx_pin, GPIO_HIGH);
        }
        else {
            gpio_write(serial->tx_pin, GPIO_LOW);
        }
        delay(serial->us);
    }
    
    gpio_write(serial->tx_pin, GPIO_HIGH);
    delay(serial->us);
}

void serial_loop (serial_t *serial, unsigned long now) {
    while (char_buffer_peek(&(serial->tx_buffer))) {
        serial_write(serial, char_buffer_read(&(serial->tx_buffer)));
    }
}
