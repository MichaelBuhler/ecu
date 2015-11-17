#include "ecu.h"
#include "lib/gpio.c"
#include "lib/systimer.c"

void setup() {
    gpio_mode(ONBOARD_LED,GPIO_OUTPUT);
    gpio_write(ONBOARD_LED,GPIO_HIGH);
}

void loop() {
    unsigned int next = 1000000;
    unsigned int state = 1;
    while(1)
    {
        if ( micros() > next ) {
            state ^= 1;
            gpio_write(ONBOARD_LED,state);
            next += 1000000;
        }
    }
}

