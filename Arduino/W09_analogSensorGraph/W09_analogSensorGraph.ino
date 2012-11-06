/*
* Send analog value over serial
 * Potentiometer attached to pin A0
 * Adam Harvey / SVA PIxD / Week 9
 * Nov. 5, 2012
 */
const int PIN_POT = A0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(PIN_POT,INPUT);
}

void loop() {
  // send the value of analog input 0:
  int val = analogRead(PIN_POT);
  Serial.println(val); // sends line break after val ("123/n")

  // wait a bit for the analog-to-digital converter 
  // to stabilize after the last reading:
  // and, we don't need *that much data
  delay(2);
}


