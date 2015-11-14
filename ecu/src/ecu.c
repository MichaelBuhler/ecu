#include "ecu.h"
#include "gpio.c"

void ecu(void) {
    unsigned int ra;
    
    gpio_mode(47,1);
    
    while (1) {
        gpio_write(47,1);
        for ( ra = 0 ; ra < 0x100000 ; ra++ ) noop(ra);
        gpio_write(47,0);
        for ( ra = 0 ; ra < 0x100000 ; ra++ ) noop(ra);
    }
}
