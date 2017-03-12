#include "serial.h"
#include "rpi.h"
#include "gpio.h"
#include "systimer.h"

void serial_init (serial_t *conn, unsigned char rx_pin, unsigned char tx_pin) {
    conn->rx = rx_pin;
    conn->tx = tx_pin;
    gpio_mode(rx_pin,GPIO_INPUT);
    gpio_mode(tx_pin,GPIO_OUTPUT);
}

void serial_begin (serial_t *conn, unsigned long baud_rate) {
    conn->us = 1000000 / baud_rate;
    gpio_write(conn->tx, GPIO_HIGH);
    delay(conn->us);
}

void serial_write (serial_t *conn, unsigned char b) {
    gpio_write(conn->tx, GPIO_LOW);
    delay(conn->us);
    
    unsigned char mask;
    for ( mask = 1; mask; mask<<=1 ) {
        if ( b&mask ) {
            gpio_write(conn->tx, GPIO_HIGH);
        }
        else {
            gpio_write(conn->tx, GPIO_LOW);
        }
        delay(conn->us);
    }
    
    gpio_write(conn->tx, GPIO_HIGH);
    delay(conn->us);
}
