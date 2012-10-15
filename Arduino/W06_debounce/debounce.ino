/*
 * Example of debounce with switch and 2 LEDs
 * Blue is not connected, yellow is connected
 * Based on Arduino->Debounce example
 * Adam Harvey / SVA PIxD
 * Oct. 15, 2012
 */

const int PIN_SWITCH = 7;     // the number of the pushbutton pin
const int PIN_LED_ON = 5; // Blue
const int PIN_LED_OFF = 4; // Yellow

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(PIN_SWITCH, INPUT);
  pinMode(PIN_LED_OFF, OUTPUT);
  pinMode(PIN_LED_ON, OUTPUT);
}

void loop() {
  // read the state of the switch into a local variable:
  int switchVal = digitalRead(PIN_SWITCH);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (switchVal != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    buttonState = switchVal;
  }

  // set the LED using the state of the button:
  digitalWrite(PIN_LED_ON,!buttonState); 
  digitalWrite(PIN_LED_OFF,buttonState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = switchVal;
}


