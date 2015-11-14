#include "ecu.h"
#include "lib/gpio.c"

void ecu(void) {
    gpio_mode(21,0);
    gpio_mode(47,1);
    
    while (1) {
        gpio_write(47, gpio_read(21) );
    }
}
