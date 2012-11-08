/*
* PIxD Lucky Cat Arm Controller
 * Nov. 7, 2012
 * Uses the small servo included with the Adafruit kit
 */


#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 

// Angles we're using to control it
const int FULL_SWING_DELAY = 200; // time it takes to swing the arm
const int HALF_SWING_DELAY = 400; // time it takes to swing the arm
const int BACK_POS = 180; // arm is all the way back
const int FORWARD_POS = 0; // arm is all the way forward
const int MID_BACK_POS = 110;
const int MID_FORWARD_POS = 50;

int curPos = 0;    // variable to store the servo position 

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 


void loop() 
{ 
  throwArmBack();
  delay(2000); // wait a little
  throwArmForward();
  delay(2000); // wait a little
  swingAndHitArm();
  delay(2000); // wait a little
  stopArm(); // pause arm in the middle
  delay(2000); // wait a little

} 

void throwArmBack(){
  Serial.println("throwArmBack()");
  myservo.write(BACK_POS);
  curPos = BACK_POS;
  delay(FULL_SWING_DELAY);  
}

void throwArmForward(){
  Serial.println("throwArmForward()");
  myservo.write(FORWARD_POS);
  curPos = FORWARD_POS;
  delay(FULL_SWING_DELAY);
}

void stopArm(){
  // go to 90 deg?
  Serial.println("stopArm()");
  if( curPos == FORWARD_POS ){
    myservo.write( MID_FORWARD_POS );
  } 
  else if (curPos == BACK_POS){
    myservo.write( MID_BACK_POS);
  }
  delay(1000);
}

void throwArmMidForward(){
  Serial.println("throwArmMidForward()");
  myservo.write( MID_FORWARD_POS );
  curPos = MID_FORWARD_POS;
  delay(HALF_SWING_DELAY); // Hold here
}

void throwArmMidBack(){
  Serial.println("throwArmMidBack()");
  myservo.write( MID_BACK_POS);
  curPos = MID_BACK_POS;
  delay(HALF_SWING_DELAY); // Hold here
}

void punchArmMidBack(){
  myservo.write( MID_BACK_POS - 25);
  delay(150);
}

void punchArmMidForward(){
  myservo.write( MID_FORWARD_POS + 25);  
  delay(150);
}

void swingAndHitArm(){
  // moves towards the plastic knob-thing
  // then sweep back to get out of the way
  if( curPos == FORWARD_POS ){
    // servo arm should be in the front position
    throwArmMidForward();
    punchArmMidBack();
    throwArmForward();
  } 
  else if(curPos == BACK_POS ){
    // servo arm should be in the back position
    throwArmMidBack();
    punchArmMidBack();
    throwArmBack();
  }

}
















