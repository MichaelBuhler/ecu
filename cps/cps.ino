#define OUTPUT_PIN 2
#define RPM 30;

unsigned long us;
unsigned long until;
unsigned char state;
unsigned char toothNum;

void setup() {
    Serial.begin(9600);
    us = 833333 / RPM;
    until = 0;
    state = 0;
    toothNum = 0;
    pinMode(OUTPUT_PIN,OUTPUT);
}

void loop() {
    while ( Serial.available() )
        Serial.write(Serial.read());
    unsigned long now = micros();
    if ( now > until ) {
        if ( state ) {
            state = 0;
            digitalWrite(OUTPUT_PIN,LOW);
        }
        else {
            state = 1;
            toothNum++;
            toothNum %= 36;
            if ( toothNum != 35 )
                digitalWrite(OUTPUT_PIN,HIGH);
        }
        until = now + us;
    }
}

