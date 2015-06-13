#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
int ledPin = 13;

int incomingByte = 0;
void setup() {
  // initialize serial:
  Serial.begin(9600);

  // make the pins outputs:

  pinMode(ledPin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

	incomingByte = Serial.read();

	Serial.print(incomingByte, DEC);

	digitalWrite(ledPin, HIGH);
	delay(100);
	digitalWrite(ledPin, LOW);

  }
}








