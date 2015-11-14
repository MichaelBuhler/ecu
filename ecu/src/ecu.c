#include "ecu.h"
#include "gpio.c"

void ecu(void) {
    unsigned int ra;

    ra = get32(GPIO_FSEL4);
    ra &= ~(7<<18);
    ra |= 1<<18;
    put32(GPIO_FSEL4,ra);

    while (1) {
        gpio_write(47,1);
        for ( ra = 0 ; ra < 0x100000 ; ra++ ) noop(ra);
        gpio_write(47,0);
        for ( ra = 0 ; ra < 0x100000 ; ra++ ) noop(ra);
    }
}
