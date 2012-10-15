/*
* Make an LED breathe
 * Oct. 1, 2012
 * Adam Harvey
 * Second attemp
 * Added code from Sean Voisen
 * http://sean.voisen.org/blog/2011/10/breathing-led-with-arduino/
 *
 */

const int PIN_LED_BLUE = 6; // Blue LED pin
const int PIN_LED_RED = 5; // Red LED pin

int brightnessValue = 0; // from 0 - 255, could also be a char
boolean goingUp = true; // are we fading up or down?

void setup(){

   // this activates the serial capabilities, and  9600 is a popular speed
  Serial.begin(9600);

}

void loop(){

  // A basic fade up/down
  basicFade( PIN_LED_RED );

  // the nice one
  breathyFade(PIN_LED_BLUE);

}

// --------------------------------------------
// The basic fader we made in class
void basicFade( int pin ){
  // 

  if( goingUp ){
    brightnessValue++;
    if( brightnessValue >= 255 ){
      // fade down
      goingUp = false;
    }

  } 
  else {
    brightnessValue--;
    if( brightnessValue < 1 ){
      // fade down
      goingUp = true;
    }
  }

  analogWrite(pin,brightnessValue);


  // output the value so we can debug it
  Serial.println(brightnessValue);

  // this helps decrease the speed of fading up/down
  delay(10);
}

// --------------------------------------------
// An advanced LED fader
void breathyFade(int pin){
  int PIN_LED_BLUE = 0;
  int p = 0;
  float val = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
  analogWrite(pin, val);
}






