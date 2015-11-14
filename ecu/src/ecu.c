#include "lib/gpio.c"
#include "lib/time.c"

#define MAIN_LED 21
#define IRQ_LED 24
#define ERROR_LED 18
#define CPS_PIN 26

volatile unsigned int timer = 0;
volatile unsigned int level = 0;
volatile char state = GPIO_HIGH;

void __attribute__((interrupt("IRQ"))) interrupt_handler(void) {
    if ( level ) {
        level = 0;
        *((unsigned long*)(GPIO_CLR0)) = (1<<IRQ_LED);
    } else {
        level = 1;
        *((unsigned long*)(GPIO_SET0)) = (1<<IRQ_LED);
    }
    *((unsigned long*)(GPIO_EDS0)) = (1<<CPS_PIN);
}

void loop(void) {
    if ( millis() > timer ) {
        if ( state ) {
            state = GPIO_LOW;
            gpio_write(MAIN_LED,GPIO_LOW);
        } else {
            state = GPIO_HIGH;
            gpio_write(MAIN_LED,GPIO_HIGH);
        }
        timer = millis() + 500;
    }
}

void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags ) {
    gpio_mode(MAIN_LED,GPIO_OUTPUT);
    gpio_write(MAIN_LED,GPIO_HIGH);
    gpio_mode(IRQ_LED,GPIO_OUTPUT);
    gpio_write(IRQ_LED,GPIO_HIGH);
    gpio_mode(ERROR_LED,GPIO_OUTPUT);
    gpio_write(ERROR_LED,GPIO_LOW);
    for ( timer = 500000 ; timer ; timer-- ) {}
    gpio_write(ERROR_LED,GPIO_HIGH);
    gpio_mode(CPS_PIN,GPIO_INPUT);
    *((unsigned long*)(GPIO_AREN0)) |= (1<<CPS_PIN);
    *((unsigned long*)(0x3F00B214)) |= (1<<20);
    _sei();
    while (1) {}
    while (1) loop();
}

/*
void error() {
    while (1) {
        gpio_write(ERROR_LED,GPIO_LOW);
        for ( timer = 0 ; timer < 500000 ; timer++ ) {}
        gpio_write(ERROR_LED,GPIO_HIGH);
        for ( timer = 0 ; timer < 500000 ; timer++ ) {}
    }
}
*/
