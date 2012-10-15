/*
 * Control a servo through Processing
 * Smooth the incoming analog pot values
 * Adam Harvey / SVA IxD
 * October 8, 2012
 *
 * Added smoothing because servo was twitchy
 *
 */

// This library ships with Arduino 1.0
#include <Servo.h> 
char val;
int servoVal = 0;


const int PIN_SERVO = 3; 
const int PIN_LED_BLUE = 5; // Blue
const int PIN_LED_YELLOW = 4; // Yellow

// Servo object
Servo myservo; 


void setup() 
{ 

  Serial.begin(9600);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);
  myservo.attach(PIN_SERVO);  // attaches the servo on pin 9 to the servo object 
}

void loop() 
{ 

  readPotValueFromSerial();

} 

void readPotValueFromSerial(){
  if (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }

  switch( val ){
  case '1':
    digitalWrite(PIN_LED_BLUE, HIGH);
    digitalWrite(PIN_LED_YELLOW, LOW);
    servoVal = 180;
    break;
  case '2':
    digitalWrite(PIN_LED_BLUE, LOW);
    digitalWrite(PIN_LED_YELLOW, LOW);
    servoVal = 135;
    break;
  case '3':
    digitalWrite(PIN_LED_YELLOW, HIGH);
    digitalWrite(PIN_LED_BLUE, LOW);
    servoVal = 90;
    break;
  case '4':
    digitalWrite(PIN_LED_YELLOW, LOW);
    digitalWrite(PIN_LED_BLUE, LOW);
    servoVal = 0;
    break;
  }
  writeServoVal();
}


void writeServoVal(){
  myservo.write(servoVal);  // sets the servo position according to the scaled value 
  delay(15); // wait for servo to catch up
  // Serial.println(servoVal);
}
















