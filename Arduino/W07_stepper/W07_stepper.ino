/*
* Stepper motor demonstration
 * Adam Harvey / SVA PIxD
 * October 22, 2012
 * Bipolar Stepper MFG Model: 42BYGH011
 * 11.2V, .33A, 46mH, 34ohms
 * More: http://www.kysanelectronics.com/Products/datasheet_display.php?recordID=2869
 * Wiring: http://www.tigoe.net/pcomp/code/circuits/motors/stepper-motors/
 * Stepper library: http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
const int STEPS = 200; // 360 / 1.8
Stepper stepper(STEPS, 10, 11, 12, 13);

void setup()
{
  Serial.begin(9600);
  // set the speed of the motor to 100 RPMs
  stepper.setSpeed(150);
}

void loop()
{
  if( Serial.available() ){
    char c = Serial.read();
    if( c > 48  && c < 58 ){
      int steps = c - 48;
      updateStepperMotor( steps );
    }
  }
}


void updateStepperMotor( int steps ){
  Serial.print("steps: ");
  Serial.println(steps);
  stepper.step(steps);
}












