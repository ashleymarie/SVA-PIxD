/*
 * Show the status of the motion sensor
 * with an LED
 * Adam Harvey / SVA PIxD
 * Oct. 15, 2012455
 */

const int PIN_PIR = 2;
const int PIN_LED_ON = 5; // Blue
const int PIN_LED_OFF = 4; // Yellow

int ledState = HIGH;         // the current state of the output pin
int pirState;             // the current reading from the input pin
int lastPirState = LOW;   // the prexvious reading from the input pin

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 1000;    // the debounce time; increase if the output flickers

void setup(){
  Serial.begin(9600);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_LED_ON,OUTPUT);
  pinMode(PIN_LED_OFF,OUTPUT);
}

void loop(){
  int pirVal = digitalRead(PIN_PIR);

  if (pirVal != lastPirState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    pirState = pirVal;
  }


  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastPirState = pirVal;
  
  
  
  // 1 means no motion, 0 means motion
  digitalWrite(PIN_LED_ON,!pirState); 
  digitalWrite(PIN_LED_OFF,pirState);
  
  Serial.println(pirState);

}




