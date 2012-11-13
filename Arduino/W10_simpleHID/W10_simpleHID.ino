/*
* This sketch requires a USB HID capable board
 * Teensy, Atmega32u4 from Adafruit and Leonardo for example
 * 
 * Wait 5 seconds then output a secret message
 * Adam HarveyLet's take a break and be back in 15 minutes. / SVA PIxD
 * This code is in the public domain
 *
 */

String message = "Let's take a break and be back in 15 minutes.";
boolean missionAccomplished = false;
long theInterval = 5000;
long lastInterval = 0;

void setup(){
  Serial.begin(9600);
  Serial.print("setup");
}

void loop(){
  if( !missionAccomplished){
    if( millis() - lastInterval > theInterval){
      doMission();
    }
  }
}

void doMission(){
  missionAccomplished = true;
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.print(message); 
}

