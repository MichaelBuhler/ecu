#define OUTPUT_PIN 2
#define RPM 30;

unsigned int us;
unsigned int times;
unsigned int i;
unsigned int j;

void setup() {
  us = 833333 / RPM;
  times = us / 16383 + 1;
  us /= times;
  pinMode(2,OUTPUT);
}

void loop() {
  for ( i = 0 ; i < 35 ; i++ ) {
    digitalWrite(OUTPUT_PIN,HIGH);
    pause();
    digitalWrite(OUTPUT_PIN,LOW);
    pause();
  }
  pause();
  pause();
}

void pause() {
  for ( j = 0 ; j < times ; j++ )
    delayMicroseconds(us);
}

