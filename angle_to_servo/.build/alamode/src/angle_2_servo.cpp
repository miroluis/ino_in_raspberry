#include <Arduino.h>
#include <Servo.h>
void setup();
void loop();
#line 1 "src/angle_2_servo.ino"
/*
  Reading a serial ASCII-encoded string.

 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.

 Circuit: Common-anode RGB LED wired like so:
 * Red cathode: digital pin 3
 * Green cathode: digital pin 5
 * blue cathode: digital pin 6
 * anode: +5V

 created 13 Apr 2012
 by Tom Igoe

 This example code is in the public domain.
 */

// pins for the LEDs:
//const int redPin = 3;
//const int greenPin = 5;
const int anglePin = 10;

//#include <Servo.h>

Servo myservo;  // create servo object to control a servo 

void setup() {
    myservo.attach(anglePin);  // attaches the servo on pin 9 to the servo object
    
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
 // pinMode(redPin, OUTPUT);
  //pinMode(greenPin, OUTPUT);
  //pinMode(anglePin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
  //  int red = Serial.parseInt();
    // do it again:
   // int green = Serial.parseInt();
    // do it again:
    int angle = Serial.parseInt();
     // Serial.println(angle, HEX);
    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
            Serial.println(angle, HEX);
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
