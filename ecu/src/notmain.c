extern void put32 ( unsigned int, unsigned int );
extern unsigned int get32 ( unsigned int );
extern void noop ( unsigned int );

#define GPFSEL4 0x3F200010
#define GPSET1  0x3F200020
#define GPCLR1  0x3F20002C

int notmain(void) {
    unsigned int ra;

    ra = get32(GPFSEL4);
    ra &= ~(7<<18);
    ra |= 1<<18;
    put32(GPFSEL4,ra);

    while (1) {
        put32(GPSET1,1<<15);
        for ( ra = 0 ; ra < 0x100000 ; ra++ )
            noop(ra);
        put32(GPCLR1,1<<15);
        for ( ra = 0 ; ra < 0x100000 ; ra++ )
            noop(ra);
    }
    return 0;
}
