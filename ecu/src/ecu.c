#include "ecu.h"
#include "lib/gpio.c"

#define SYSTIMERCLO 0x3F003004

void setup() {
    gpio_mode(ONBOARD_LED,GPIO_OUTPUT);
    gpio_write(ONBOARD_LED,GPIO_HIGH);
}

void loop() {
    unsigned int now = 0;
    unsigned int next = 1000000;
    unsigned int state = 1;
    while(1)
    {
        now = get32(SYSTIMERCLO);
        if ( now > next ) {
            state ^= 1;
            gpio_write(ONBOARD_LED,state);
            next += 1000000;
        }
    }
}

