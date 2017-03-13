#ifndef ECU_H
#define ECU_H

#define SERIAL_RX_PIN 22
#define SERIAL_TX_PIN 27
#define SERIAL_BAUD_RATE 9600

#define CPS_PIN 4
#define IGNITION1_PIN 18
#define IGNITION2_PIN 23
#define IGNITION3_PIN 24
#define IGNITION4_PIN 25

void setup ();
void loop ();
void ecu_loop (unsigned long);

#endif