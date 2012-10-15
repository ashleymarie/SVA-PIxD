/*
 * Show the status of the motion sensor
 * with an LED
 * Adam Harvey / SVA PIxD
 * Oct. 15, 2012455
 */

const int PIN_PIR = 2;
const int PIN_LED_ON = 5; // Blue
const int PIN_LED_OFF = 4; // Yellow

void setup(){
  Serial.begin(9600);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_LED_ON,OUTPUT);
  pinMode(PIN_LED_OFF,OUTPUT);
}

void loop(){
  int pirVal = digitalRead(PIN_PIR);
  // 1 means no motion, 0 means motion
  digitalWrite(PIN_LED_ON,!pirVal); 
  digitalWrite(PIN_LED_OFF,pirVal);
  Serial.println(pirVal);
  delay(20);
}



