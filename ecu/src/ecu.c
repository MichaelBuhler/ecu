#include "ecu.h"
#include "rpi.h"
#include "gpio.h"
#include "serial.h"
#include "systimer.h"

unsigned char synced;
unsigned char toothNum;
unsigned char state;
unsigned char cycle;
unsigned long upTime;
unsigned long downTime;
unsigned long position;
serial_t serial;

void setup () {
    gpio_mode(CPS_PIN, GPIO_INPUT);
    gpio_mode(ONBOARD_LED_PIN, GPIO_OUTPUT);
    gpio_mode(IGNITION1_PIN, GPIO_OUTPUT);
    gpio_mode(IGNITION2_PIN, GPIO_OUTPUT);
    gpio_mode(IGNITION3_PIN, GPIO_OUTPUT);
    gpio_mode(IGNITION4_PIN, GPIO_OUTPUT);
    synced = 0;
    toothNum = 0;
    state = 0;
    cycle = 0;
    upTime = 0;
    downTime = 0;
    position = 0;
    serial_init(&serial, SERIAL_RX_PIN, SERIAL_TX_PIN);
    serial_begin(&serial, SERIAL_BAUD_RATE);
}

void loop () {
    unsigned long now = micros();
    serial_loop(&serial, now);
    ecu_loop(now);
}

void ecu_loop (unsigned long now) {

    if ( synced ) {

        if ( state && gpio_read(CPS_PIN) == GPIO_LOW ) {
            state = 0;
            downTime = now;
            position = 360000 * cycle + toothNum * 10000 + 5000;
        }
        else if ( state == 0 && gpio_read(CPS_PIN) ) {
            state = 1;
            upTime = now;
            toothNum++;
            if ( toothNum == 36 ) {
                toothNum = 0;
                cycle ^= 1;
            }
            position = 360000 * cycle + toothNum * 10000;
        }
        else if ( upTime > downTime ) {
            position = 360000 * cycle + 10000 * toothNum + ( 5000 * (now-upTime) ) / (upTime-downTime);
        }
        else {
            position = 360000 * cycle + 10000 * toothNum + 5000 + ( 5000 * (now-downTime) ) / (downTime-upTime);
        }

        if ( position >= 0 && position <= 5000 ) {
            gpio_write(IGNITION1_PIN, GPIO_HIGH);
        }
        else {
            gpio_write(IGNITION1_PIN, GPIO_LOW);
        }

        if ( position >= 180000 && position <= 185000 ) {
            gpio_write(IGNITION3_PIN, GPIO_HIGH);
        }
        else {
            gpio_write(IGNITION3_PIN, GPIO_LOW);
        }

        if ( position >= 360000 && position <= 365000 ) {
            gpio_write(IGNITION4_PIN, GPIO_HIGH);
        }
        else {
            gpio_write(IGNITION4_PIN, GPIO_LOW);
        }

        if ( position >= 540000 && position <= 545000 ) {
            gpio_write(IGNITION2_PIN, GPIO_HIGH);
        }
        else {
            gpio_write(IGNITION2_PIN, GPIO_LOW);
        }

        if ( position == 0 ) {
            serial_write(&serial, 65);
        }

    }
    else {

        if ( state && gpio_read(CPS_PIN) == 0 ) {
            state = 0;
            downTime = now;
        }
        else if ( state == 0 && gpio_read(CPS_PIN) ) {
            state = 1;
            if ( upTime && downTime && now - downTime > 2 * (downTime - upTime) ) {
                position = 0;
                synced = 1;
                toothNum = 0;
                gpio_write(ONBOARD_LED_PIN, GPIO_HIGH);
            }
            upTime = now;
        }

    }
}
