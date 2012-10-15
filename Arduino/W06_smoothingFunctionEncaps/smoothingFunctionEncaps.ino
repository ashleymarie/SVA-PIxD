
const int PIN_LIGHT = A0;
const int PIN_POT = A2;

// Smoothing

// ------------------------------------------------
// Light
const int numReadings = 10;
int lightReadings[numReadings];
int lightIndex = 0;
long lightTotal = 0;   
int lightAverage = 0;

// Potentiometer
int potReadings[numReadings];
int potIndex = 0;            
long potTotal = 0;            
int potAverage = 0;

// Can add other sensors to smooth here
// ...
// ...
// ...

void setup()
{
  // initialize serial communication with computer:
  Serial.begin(9600);                   
  // initialize all the readings to 0: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++){
    lightReadings[thisReading] = 0;
    potReadings[thisReading] = 0;
  }
}

void loop() {
  // subtract the last reading:

  int lightVal =   analogRead(PIN_LIGHT); 
  //smoothValuesFirstTry(lightVal, lightIndex, lightTotal, lightAverage, lightReadings);
  smoothValuesSecondTry(lightVal, lightIndex, lightTotal, lightAverage, lightReadings);
  Serial.print("lightAverage\t");
  Serial.print(lightAverage);

  int potVal =   analogRead(PIN_POT); 
  //smoothValuesFirstTry(potVal, potIndex, potTotal, potAverage, potReadings);
  smoothValuesSecondTry(potVal, potIndex, potTotal, potAverage, potReadings);

  Serial.print("\tpotAverage\t");
  Serial.println(potAverage);

}

void smoothValuesFirstTry(int val, int index, int total, int average, int readings[]){
  // Passing by value
  total = total - readings[index];         
  // read from the sensor:  
  readings[index] = val;
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings;         
  // send it to the computer as ASCII digits
  delay(1);        // delay in between reads for stability

  // At this point all of the work we've done inside this fucntion is "erased"

}


void smoothValuesSecondTry(int val, int &fIndex, long &fTotal, int &fAvg,int* fReadings  ){
  // Passing by reference
  // These are the actual variables from in loop(), not just temporary function variables
  // subtract the last reading:
  fTotal -= fReadings[fIndex];         
  // read from the sensor:  
  fReadings[fIndex] = val;
  // add the reading to the total:
  fTotal += fReadings[fIndex];       
  // advance to the next position in the array:  
  fIndex = fIndex + 1;                    

  // if we're at the end of the array...
  if (fIndex >= numReadings)              
    // ...wrap around to the beginning: 
    fIndex = 0;                           

  // calculate the average:
  fAvg = fTotal / numReadings;

  // our work is not "erased" becuse we were working with the actual variable
  // the pointer provides it's address

}







