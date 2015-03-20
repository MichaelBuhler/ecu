#include "lib/gpio.c"

volatile unsigned int timer = 0;

void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags ) {
    gpio_mode(4,GPIO_OUTPUT);
    gpio_mode(17,GPIO_INPUT);
    while (1) {
        gpio_write(4,gpio_read(17));
        for ( timer = 0 ; timer < 1000000 ; timer++ ) {}
    }
}

void exit(int code) {
    while (1) {}
}
