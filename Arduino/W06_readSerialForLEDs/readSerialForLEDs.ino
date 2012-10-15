/*
* Receive a byte and translate it to the servo controller
 * 48	0
 * 49	1
 * 50	2
 * 51	3
 * 52	4
 * 53	5
 * 54	6
 * 55	7
 * 56	8
 * 57	9
 */
char val; // Data received from the serial port
const int PIN_LED_BLUE = 5; // Blue
const int PIN_LED_YELLOW = 4; // Yellow

void setup() {
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {

  if (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }

  switch( val ){
  case 'B':
    digitalWrite(PIN_LED_BLUE, HIGH);
    break;
  case 'b':
    digitalWrite(PIN_LED_BLUE, LOW);
    break;
  case 'Y':
    digitalWrite(PIN_LED_YELLOW, HIGH);
    break;
  case 'y':
    digitalWrite(PIN_LED_YELLOW, LOW);
    break;
  default:
    // none of the criteria matched
    break;
  }

  /*
  if( val == 'B'){
    // turn on blue led
  } 
  else if( val == 'b'){
    // turn off blue led
  } 
  else if( val == 'y'){
    // turn off yellow led
  } 
  else if( val == 'Y'){
    // turn on yellowed led
  } 
  else {  
    // byte doesn't match our criteria
  }
*/
  delay(10); // Wait 10 milliseconds for next reading
}






