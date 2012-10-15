/*
 * Calculate # of loops executed by Adruino per second
 * Oct. 1, 2012
 * Adam Harvey
 * First attempt result, about 146000 cycles per second on Uno
 */

long counter = 0; // store the number of loops

long myInterval = 1000; // count loops for this many milliseconds
long lastInterval = 0; // store the last time we printed it

boolean useMs = false; // use ms or seconds

void setup(){

  Serial.begin(9600); // activate serial capabilities

}

void loop(){

  // print either in ms or in s
  if( useMs ){
    speedTestInMs();
  } 
  else {
    speedTestInSeconds();
  }

}

// An encapsulated version of our speed test
void speedTestInMs(){

  counter++; // +1 for every loop

  if( millis() - lastInterval > myInterval ){
    lastInterval = millis(); // store current time
    Serial.print(counter);
    Serial.print("\tper\t");
    Serial.print(myInterval);
    Serial.println("\tms\t"); // formatted with tabs

    counter = 0; // reset the counter

  }

}
// Similar function but report the speed with seconds, stripped commenting
void speedTestInSeconds(){

  counter++;

  if( millis() - lastInterval > myInterval ){
    lastInterval = millis();

    Serial.print(counter);
    Serial.print("\tper\t");
    Serial.print(myInterval / 1000);
    Serial.println("\tseconds\t");

    counter = 0;

  }

}










