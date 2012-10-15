/*
* Test switching
 * Oct. 8, 2012
 */

const char AUDIO_ON = 1;
const char AUDIO_OFF = 2;

const char LED_ON = 3;
const char LED_OFF = 4;

const char PIN_START_STOP_BUTTON = 12;
char state, substate;

void setup(){

  Serial.begin(9600);
  pinMode(PIN_START_STOP_BUTTON, INPUT);

  state = AUDIO_OFF;

}

void loop(){

  readStartStopButton();

  updateMode();

}

void readPotentiometer(){
}

void updateMode(){

  switch( state ){
  case AUDIO_ON:
    playMelody();
    break;
  case AUDIO_OFF:
    turnOffMelody();
    break;
  }

  switch( substate ){
  case LED_ON:
    turnLEDsOn();
    break; 
  case LED_OFF:
    turnLEDsOff();
    break;
  }

}

void oldUpdateMode(){
  if( state == AUDIO_ON ){
    playMelody();
  } 
  else {
    turnOffMelody();
  }
}

void readStartStopButton(){
  int val = digitalRead( PIN_START_STOP_BUTTON );
  if( val == HIGH ){
    mode = AUDIO_ON;
  } 
  else if( val == LOW ){
    mode = AUDIO_OFF; 
  }
}

void playMelody(){
  // play tone with tone library
}

void turnOffMelody(){
  // not play audio
}





