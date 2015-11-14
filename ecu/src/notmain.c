#include "gpio.h"

extern void put32 ( unsigned int, unsigned int );
extern unsigned int get32 ( unsigned int );
extern void noop ( unsigned int );

int notmain(void) {
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
    return 0;
}
