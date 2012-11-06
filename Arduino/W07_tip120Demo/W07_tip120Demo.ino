/*
 * TIP120 basic demonstration
 * Adam Harvey / SVA PIxD
 * October 22, 2012
 * Control the Adafruit motor
 * Operates between 4.5 - 9V
 * Try at 5V , try at 9V
 *
 */
const int PIN_BASE = 3; // PWM pin
long delayAmt = 1000;
int incAmt = 10;

void setup() {                
  pinMode(PIN_BASE, OUTPUT);     
}

void loop() {
  // Turn the base voltage high (to 5V)
  // this allows current to flow through the transistor
  digitalWrite(PIN_BASE, HIGH);
  delay(delayAmt);            
  // Turn the base voltage high (to 0V)
  // this stops current flowing through the transistor
  digitalWrite(PIN_BASE, LOW); 
  delay(delayAmt);          

  if( Serial.available() ){
    char c = Serial.read();
    if( c == 'u'){
      adjustSpeed( incAmt * multiplier );
    } 
    else if( c > 48 && c < 58 ){
      // > 0 and <= 9
      multipler = c - 48;
    }
  }
  // You can turn this off and on as fast as you want
}

void adjustSpeed(int i){
  delayAmt = (multiplier * delayAmt );
  Serial.print("delayAmt: ");
  Serial.println(delayAmt);
}






