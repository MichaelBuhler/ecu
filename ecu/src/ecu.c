#include "rpi.h"
#include "gpio.h"

#define CPS_PIN 7
#define NUM_CYLINDERS 4
#define IGNITION1 18
#define IGNITION2 23
#define IGNITION3 24
#define IGNITION4 25

unsigned int state;
unsigned int position;

void setup() {
    gpio_mode(CPS_PIN,GPIO_INPUT);
    gpio_mode(ONBOARD_LED,GPIO_OUTPUT);
    gpio_mode(IGNITION1,GPIO_OUTPUT);
    gpio_mode(IGNITION2,GPIO_OUTPUT);
    gpio_mode(IGNITION3,GPIO_OUTPUT);
    gpio_mode(IGNITION4,GPIO_OUTPUT);
    state = 0;
    position = 0;
}

void loop() {
    if ( state && gpio_read(CPS_PIN) == 0 ) {
        state = 0;
        gpio_write(ONBOARD_LED,0);
        position += 5;
        position %= 720;
    }
    else if ( state == 0 && gpio_read(CPS_PIN) ) {
        state = 1;
        gpio_write(ONBOARD_LED,1);
        position += 5;
        position %= 720;
    }
    if ( position == 0 )
        gpio_write(IGNITION1,1);
    else
        gpio_write(IGNITION1,0);
    if ( position == 180 )
        gpio_write(IGNITION3,1);
    else
        gpio_write(IGNITION3,0);
    if ( position == 360 )
        gpio_write(IGNITION4,1);
    else
        gpio_write(IGNITION4,0);
    if ( position == 540 )
        gpio_write(IGNITION2,1);
    else
        gpio_write(IGNITION2,0);
}
