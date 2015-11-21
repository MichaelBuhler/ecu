#include "serial.h"
#include "gpio.h"

void serial_init(serial_t *conn, unsigned char rx_pin, unsigned char tx_pin, unsigned long baud_rate) {
    conn->rx = rx_pin;
    conn->tx = tx_pin;
    conn->us = 1000000 / baud_rate;
}

void serial_write(serial_t *conn, unsigned char b) {
    gpio_write(conn->tx,GPIO_LOW);
    delay(conn->us);
    
    unsigned char mask;
    for ( mask = 1; mask; mask<<=1 ) {
        if ( b&mask) gpio_write(conn->tx,GPIO_HIGH);
        else gpio_write(conn->tx,GPIO_LOW);
        delay(conn->us);
    }
    
    gpio_write(conn->tx,GPIO_HIGH);
    delay(conn->us);
}
