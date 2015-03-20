unsigned int us;
byte i;

void setup() {
  us = 833;
  pinMode(2,OUTPUT);
}

void loop() {
  for ( i = 0 ; i < 35 ; i++ ) {
    digitalWrite(2,HIGH);
    delayMicroseconds(us);
    digitalWrite(2,LOW);
    delayMicroseconds(us);
  }
  delayMicroseconds(us);
  delayMicroseconds(us);
}
