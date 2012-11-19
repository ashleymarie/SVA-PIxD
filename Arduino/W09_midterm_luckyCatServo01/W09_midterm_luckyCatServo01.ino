/*
* PIxD Lucky Cat Arm Controller
 * Nov. 7, 2012
 * Uses the small servo included with the Adafruit kit
 */


#include <Servo.h> 

// Pin assignments
const int PIN_CAT_ARM_SERVO = 3; // PWM

// Servo object
Servo myservo;

// Angles we're using to control it
const int BACK_POS = 180; // arm is all the way back
const int FORWARD_POS = 0; // arm is all the way forward
// adjust these depending on how you connected your black plastic servo piece
const int MID_BACK_POS = 90;
const int MID_FORWARD_POS = 80;
// Delay (it takes the servo a few hundred milliseconds to move to its target)
const int FULL_SWING_DELAY = 200; // time it takes to swing the arm
const int HALF_SWING_DELAY = 1000; // time it takes to swing the arm
const int STOP_DELAY = 1000; // time paused in the middle

// keep track of where the arm is
int curPos = 0;

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(PIN_CAT_ARM_SERVO);  // attach to 
} 


void loop() 
{ 
  // Runs through the basic actions of the lucky cat arm
  // throwArmBack, throwArmForward, and stopArm
  
  throwArmBack();
  delay(2000);

  stopArm(); // pause arm in the middle
  delay(2000);
  
  throwArmForward();
  delay(2000);
  
  stopArm(); // pause arm in the middle
  delay(2000);

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
    curPos = MID_FORWARD_POS; 
  } 
  else if (curPos == BACK_POS){
    myservo.write( MID_BACK_POS);
    curPos = MID_BACK_POS;
  }
  delay(STOP_DELAY);
}


// Not currently using this, for reference
/*
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
 */




















