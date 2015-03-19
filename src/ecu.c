#include "lib/gpio.c"

volatile unsigned int timer = 0;

void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags ) {
    gpio_pinMode(4,GPIO_OUTPUT);
    gpio_pinMode(17,GPIO_INPUT);
    while (1) {
        gpio_digitalWrite(4,gpio_digitalRead(17));
        for ( timer = 0 ; timer < 1000000 ; timer++ ) {}
    }
}

void exit(int code) {
    while (1) {}
}
