int ledPin = 13;
void setup() {
    myservo.attach(anglePin);  // attaches the servo on pin 9 to the servo object
    
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
 // pinMode(redPin, OUTPUT);
  //pinMode(greenPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {


//digitalWrite(ledPin, HIGH);

//delay(100);
//digitalWrite(ledPin, LOW);
//digitalToggle(ledPin);
    // look for the next valid integer in the incoming serial stream:
  //  int red = Serial.parseInt();
    // do it again:
   // int green = Serial.parseInt();
    // do it again:
    int angle = Serial.parseInt();

      Serial.print(angle, HEX);

     // Serial.println(angle, HEX);
    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {

digitalWrite(ledPin, HIGH);
delay(100);
digitalWrite(ledPin, LOW);

int lixo = Serial.read();

            Serial.println(angle, HEX);
            Serial.println(lixo, HEX);
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
     // red = 255 - constrain(red, 0, 255);
     // green = 255 - constrain(green, 0, 255);
      angle = constrain(angle, 0, 180);

      // fade the red, green, and blue legs of the LED:
    //  analogWrite(redPin, red);
      //analogWrite(greenPin, green);
     // analogWrite(anglePin, angle);
 // val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(angle);                  // sets the servo position according to the scaled value 
      // print the three numbers in one string as hexadecimal:
      //Serial.print(red, HEX);
      //Serial.print(green, HEX);
      Serial.println(angle, HEX);
    }
  }
}








