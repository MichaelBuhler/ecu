#include "ecu.h"
#include "gpio.h"

void ecu(void) {
    unsigned int ra;

    ra = get32(GPIO_FSEL4);
    ra &= ~(7<<18);
    ra |= 1<<18;
    put32(GPIO_FSEL4,ra);

    while (1) {
        put32(GPIO_SET1,1<<15);
        for ( ra = 0 ; ra < 0x100000 ; ra++ )
            noop(ra);
        put32(GPIO_CLR1,1<<15);
        for ( ra = 0 ; ra < 0x100000 ; ra++ )
            noop(ra);
    }
}
