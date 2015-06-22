const int ledPin = 13;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(ledPin, OUTPUT);

}

void loop() {

//      Serial.println("ola");
//delay(1000);

  // if there's any serial available, read it:
  while (Serial.available() > 0) {

      Serial.println(Serial.read(), DEC);

    if (Serial.read() == 10) {

      // print the three numbers in one string as hexadecimal:
      Serial.println(Serial.read(), DEC);

	digitalWrite(ledPin, HIGH);
delay(1000);
	digitalWrite(ledPin, LOW);
delay(1000);


    }
  }
}

