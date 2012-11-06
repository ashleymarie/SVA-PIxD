/*
* Display the L train status
 * Adam Harvey / SVA PIxD Week 0
 * Nov. 5, 2012
 *
 * This code is in the public domain.
 */

const int PIN_OFF = 4;
const int PIN_ON = 5;

boolean trainStatus = false;

void setup(){

  Serial.begin(9600);
  pinMode(PIN_OFF, OUTPUT);
  pinMode(PIN_ON, OUTPUT);

}

void loop(){

  if( Serial.available() ) {
    char c = Serial.read();
    if( c == 'Y'){
      setYupLights();
    } 
    else if( c == 'N'){
      setNopeLights();
    } 
  }
}

void setYupLights(){
  digitalWrite(PIN_OFF, LOW);
  digitalWrite(PIN_ON, HIGH);
}

void setNopeLights(){
  digitalWrite(PIN_OFF, HIGH);
  digitalWrite(PIN_ON, LOW);
}




