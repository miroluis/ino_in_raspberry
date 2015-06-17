
/*
 This circuit colects:
 - soil moisture in pin A1
 - Light intensity in pin A0
 - Air temperature and humidity in pin 12 and 13 (digitaly)

The data are send to the serial port.

 created 13 Jun. 2015
 modified 14 Jun 2015
 by BelMiro Luis

 This example code is in the public domain.

 */


#include <SHT1x.h>
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int moisteurPin = A1;  // Analog input pin that the potentiometer is attached to


int sensorValue = 0;        // value read from the pot
int moisteurVal = 0;
int outputValue = 0;        // value output to the PWM (analog out)



// Specify data and clock connections and instantiate SHT1x object
#define dataPin  12
#define clockPin 13
SHT1x sht1x(dataPin, clockPin);

float temp_c;
float temp_f;
float humidity;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

}

String str_recv;

void loop() {
//   myservo.write(pos);              // tell servo to go to position in variable 'pos'   
  //     Serial.print("pos");
    //   Serial.println(pos, DEC);

  // if there's any serial available, read it:
  str_recv = "";
  while (Serial.available() > 0) {
	str_recv = str_recv + Serial.readString();
	Serial.print(str_recv);
      if (str_recv =="Open\n") {
      //  pos = 0; // send servo to 0
       // Serial.println("equals");
         myservo.attach(11);  // attaches the servo on pin 11 to the servo object 
         myservo.write(0);
         delay(2000); // 2 seconds to achive the desired position
         myservo.detach();  // attaches the servo on pin 11 to the servo object 
      }
      else{
         myservo.attach(11);  // attaches the servo on pin 11 to the servo object 
         myservo.write(180);
         delay(2000); // 2 seconds to achive the desired position
         myservo.detach();  // attaches the servo on pin 11 to the servo object        
      }


	//Serial.println(str_recv);
    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      //Serial.println(str_recv);

    }
  }


  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  moisteurVal = analogRead(moisteurPin);


  // print the results to the serial monitor:
  Serial.print("light = " );
  Serial.print(sensorValue);
  Serial.print("\t moisteur = ");
  Serial.println(moisteurVal);

  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();

  // Print the values to the serial port
  Serial.print("Temperature: ");
  Serial.print(temp_c, DEC);
  Serial.print("C / ");
  Serial.print(temp_f, DEC);
  Serial.print("F. Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  delay(10);
}

