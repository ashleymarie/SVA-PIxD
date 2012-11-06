/*
 * Relay basic demonstration
 * Adam Harvey / SVA PIxD
 * October 22, 2012
 * Using example from Adafruit Cookbook
 * Toggle relay on/off
 *
 */
const int PIN_RELAY = 2;

void setup() {                
  pinMode(PIN_RELAY, OUTPUT);     
}

void loop() {
  // Turns the relay on
  // relay consumes power when open (on)
  digitalWrite(PIN_RELAY, HIGH);
  delay(1000);            
  // turn the relay off
  // no power is consumed
  digitalWrite(PIN_RELAY, LOW); 
  delay(1000);          

  // You can turn this off and off fast, but there is a limit to mechanical relays
  // There is also a lifespan for a few hundred thousand* or so clicks
}





