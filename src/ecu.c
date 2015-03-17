#ifdef RPI2
    #define GPIO_BASE 0x3F200000UL
#else
    #define GPIO_BASE 0x20200000UL
#endif

volatile unsigned int* GPFSEL0 = (unsigned int*)(GPIO_BASE);
volatile unsigned int* GPFSEL1 = (unsigned int*)(GPIO_BASE+0x04);
volatile unsigned int* GPFSEL2 = (unsigned int*)(GPIO_BASE+0x08);
volatile unsigned int* GPFSEL3 = (unsigned int*)(GPIO_BASE+0x0C);
volatile unsigned int* GPFSEL4 = (unsigned int*)(GPIO_BASE+0x10);
volatile unsigned int* GPFSEL5 = (unsigned int*)(GPIO_BASE+0x14);
volatile unsigned int* GPSET0  = (unsigned int*)(GPIO_BASE+0x1C);
volatile unsigned int* GPSET1  = (unsigned int*)(GPIO_BASE+0x20);
volatile unsigned int* GPCLR0  = (unsigned int*)(GPIO_BASE+0x28);
volatile unsigned int* GPCLR1  = (unsigned int*)(GPIO_BASE+0x2C);

volatile unsigned int timer = 0;

int main(void) {
    *GPFSEL0 |= (1<<12);
#ifdef RPI2
    *GPFSEL4 |= (1<<21);
#else
    *GPFSEL1 |= (1<<18);
#endif
    while (1) {
        *GPCLR0 = (1<<4);
#ifdef RPI2
        *GPCLR1 = (1<<15);
#else
        *GPCLR0 = (1<<16);
#endif
        for ( timer = 0 ; timer < 500000 ; timer++ ) {}
        *GPSET0 = (1<<4);
#ifdef RPI2
        *GPSET1 = (1<<15);
#else
        *GPSET0 = (1<<16);
#endif
        for ( timer = 0 ; timer < 500000 ; timer++ ) {}
    }
    return 0;
}

void exit(int code) {
    while (1) {}
}
