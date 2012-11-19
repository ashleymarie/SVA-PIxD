/* 
 * Week 11 Serial Examples 
 * Nov. 19, 2012
 * SVA PIx
 
 */

const int PIN_PB = 12;
const int PIN_LIGHT = A1;
const int PIN_POT = A0;
const int PIN_LED_RED = 8;
const int PIN_LED_WHITE = 4;



void setup(){

  Serial.begin(9600);

  pinMode(PIN_PB,INPUT);
  pinMode(PIN_POT,INPUT);
  pinMode(PIN_LIGHT,INPUT);

  pinMode(PIN_LED_RED,OUTPUT);
  pinMode(PIN_LED_WHITE,OUTPUT);

}



void loop(){

  int val;  
  int id; // function scope

  id = 1; // potentiometer
  val = analogRead(PIN_POT);

  Serial.print(val); // the sensor val
  Serial.print(',');
  // Serial.print('\n');

  id = 2;
  val = analogRead(PIN_LIGHT);
  Serial.print(val);
  Serial.print(',');


  id = 3;
  val = digitalRead( PIN_PB);
  Serial.println(val);



  /// ------

  //val = analogRead( PIN_POT );
  //Serial.print( val );
  //Serial.print( "," );

  //val = digitalRead( PIN_PB );
  //Serial.println( val );

  // entire program PAUSES HERE
  delay(3);

  // resumes normal
}

/*
void serialEvent(){
 while (Serial.available()) {
 // get the new byte:
 char inChar = (char)Serial.read(); 
 // add it to the inputString:
 inputString += inChar;
 // if the incoming character is a newline, set a flag
 // so the main loop can do something about it:
 if (inChar == '\n') {
 stringComplete = true;
 } 
 }
 }
 */





