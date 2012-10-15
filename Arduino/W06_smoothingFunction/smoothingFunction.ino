

// Pins
const int PIN_LIGHT = A0;
const int PIN_POT = A2;

// Smoothing

// ------------------------------------------------
// Light
const int numReadings = 10;
int readings[numReadings];
int index = 0;
long total = 0;   
int average = 7;



void setup()
{
  // initialize serial communication with computer:
  Serial.begin(9600);
  pinMode(PIN_POT,INPUT);
  pinMode(PIN_LIGHT,INPUT);

  // initialize all the readings to 0: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;          
}

void loop() {
  // subtract the last reading:

  // int val, int _index, int _total, int _average, int _readings[])
  int val = analogRead(PIN_LIGHT);
  smoothValuesFirstTry( val, index, total, average, readings );
  //int sum = sumMyArray(readings);

  Serial.print("Average\t");
  Serial.println(average);

}

int sumMyArray( int[] values){
  int a = 1;
  // numReadings = 10
  int sum = 0;
  for( int i = 0; i < numReadings; i++){
    sum += readings[i];
  }

  return sum;
}
void smoothValuesSecondTry(int val, int &fIndex, int &fTotal, int &fAvg,int* fReadings  ){
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




void smoothValuesFirstTry(int _val, int _index, int _total, int _average, int _readings[]){
  // Passing by value
  _total = _total - _readings[_index];         
  // read from the sensor:  
  _readings[_index] = _val;
  // add the reading to the total:
  _total= _total + _readings[_index];       
  // advance to the next position in the array:  
  _index = _index + 1;                    

  // if we're at the end of the array...
  if (_index >= numReadings)              
    // ...wrap around to the beginning: 
    _index = 0;                           

  // calculate the average:
  _average = _total / numReadings;         
  // send it to the computer as ASCII digits
  delay(1);        // delay in between reads for stability

  // At this point all of the work we've done inside this fucntion is "erased"

}








