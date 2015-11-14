#include "ecu.h"
#include "lib/gpio.c"

#define INPUT_PIN 21

void setup() {
    gpio_mode(INPUT_PIN,0);
    gpio_mode(ONBOARD_LED,1);
}

void loop() {
    gpio_write(ONBOARD_LED, gpio_read(INPUT_PIN) );
}
