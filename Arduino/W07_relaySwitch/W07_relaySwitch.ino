/*
 * Relay switch demonstration
 * Adam Harvey / SVA PIxD
 * October 22, 2012
 * Control several components using a relay to toggle power On/Off
 *
 */
const int PIN_RELAY = 2;

void setup() {                
  pinMode(PIN_RELAY, OUTPUT);     
}

void loop() {
  // Turn the transistor pin HIGH allowing current to flow through
  // And switching the relay into the open position
  digitalWrite(led, HIGH);
  delay(1000);            
  // Turn the transistor pin LOW preventing any current from moving through
  // And switching the relay into the closed position
  digitalWrite(led, LOW); 
  delay(1000);            
}

