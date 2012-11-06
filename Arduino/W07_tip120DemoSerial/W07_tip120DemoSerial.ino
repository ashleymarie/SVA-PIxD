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
long delayInterval = 1000;
long onTime = 100;
int incAmt = 10;
int multiplier = 1;
long lastDelayTime = 0;
boolean baseState = false;

void setup() {                
  pinMode(PIN_BASE, OUTPUT);     
  Serial.begin(9600);
}

void loop() {
  // Turn the base voltage high (to 5V)
  // this allows current to flow through the transistor
  if( baseState ){
    if( millis() - lastOn > onTime ){
      baseState = !baseState;
      digitalWrite(PIN_BASE, baseState);
    }
  }
  if( millis() - delayInterval > lastDelayTime){
    lastDelayTime = millis();
    baseState = !baseState;
    digitalWrite(PIN_BASE, baseState);
    lastOn = millis();
  }

  if( Serial.available() ){
    char c = Serial.read();
    if( c == 'u'){
      adjustSpeed( incAmt * multiplier );
    } 
    else if( c > 48 && c < 58 ){
      // > 0 and <= 9
      multiplier = c - 48;
    }
  }
}

void adjustSpeed(int i){
  delayInterval = (multiplier * delayInterval );
  Serial.print("delayInterval: ");
  Serial.println(delayInterval);
}








