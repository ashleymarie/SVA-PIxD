/*
 * Example of flickering switch w/o debounc
 * Blue is not connected, yellow is connected
 * Adam Harvey / SVA PIxD
 * Oct. 15, 2012455
 */

const int PIN_SWITCH = 7;
const int PIN_LED_ON = 5; // Blue
const int PIN_LED_OFF = 4; // Yellow

void setup(){
  Serial.begin(9600);
  pinMode(PIN_SWITCH, INPUT);
  pinMode(PIN_LED_ON,OUTPUT);
  pinMode(PIN_LED_OFF,OUTPUT);
}

void loop(){
  int pirVal = digitalRead(PIN_SWITCH);
  // 1 means no motion, 0 means motion
  digitalWrite(PIN_LED_ON,!pirVal); 
  digitalWrite(PIN_LED_OFF,pirVal);
  //Serial.println(pirVal);
//  delay(20);
}



