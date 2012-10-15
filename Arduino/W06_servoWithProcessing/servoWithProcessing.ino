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

// Digital I/O
const int PIN_SERVO = 3; 
const int PIN_POT = A2;

// Servo object
Servo myservo; 

// smoothing variables taken from Smoothing Example in File > Examples
unsigned int potVal;
unsigned int servoVal;
const int numReadings = 10;
int readings[numReadings];
int indexReading = 0;
int totalReadings = 0;
int averagePotVal = 0;


void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(PIN_SERVO);  // attaches the servo on pin 9 to the servo object 

  // initialize smoothing values
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;   
} 

void loop() 
{ 
  // Read the pot val
  // readPotValue(); // was twitchy
  readAndSmoothValue(); // smoother

  // Write the servo value
  readPotValueFromPot();

} 

void readPotValueFromPot(){
  potVal = analogRead(PIN_POT);
  servoVal = map(potVal, 0, 1023, 1, 179); // map from 0 deg to 180 deg
}


void writeServoVal(){
  myservo.write(servoVal);  // sets the servo position according to the scaled value 
  delay(15); // wait for servo to catch up
  // Serial.println(servoVal);
}


void doServoTest(){
  int pos;
  for ( pos = 0; pos < 180; pos++){
    myservo.write(pos);
    delay(1);
  } 
  for (pos = 180; pos > 0; pos--){
    myservo.write(pos);
    delay(15);
  } 
}


// Modified smoothing example code, tweaked for the potentiometer analog input
void readAndSmoothValue(){

  totalReadings = totalReadings - readings[indexReading];         
  // read from the sensor:  
  readings[indexReading] = map(analogRead(PIN_POT),0, 1024 ,0 ,180);
  // add the reading to the total:
  totalReadings= totalReadings + readings[indexReading];       
  // advance to the next position in the array:  
  indexReading = indexReading + 1;                    

  // if we're at the end of the array...
  if (indexReading >= numReadings)              
    // ...wrap around to the beginning: 
    indexReading = 0;                           

  // calculate the average:
  servoVal = totalReadings / numReadings;
}














