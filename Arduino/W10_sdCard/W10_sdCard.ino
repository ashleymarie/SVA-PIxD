/*
  SD card datalogger
 
 This example shows how to log data from three analog sensors 
 to an SD card using the SD library.
 
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

#include <SD.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 4;
File dataFile;
boolean logging = true;
const char PIN_LED1 = 7;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  pinMode(PIN_LED1,OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }

  Serial.println("card initialized.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  dataFile = SD.open("datalog.txt", FILE_WRITE);
}

void loop()
{
  // log data to sd card
  if( logging ){
    runLogger();
  }

  // Limit how fast we log
  delay(1000);
}

void runLogger(){
  String dataString = "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ","; 
    }
  }

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    // print to the serial port too:
    Serial.print("wrote: ");
    Serial.println(dataString);
    blinkLED(PIN_LED1,1,100); // once for 100ms
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 

  // Limit the amount of data
  if( millis() > 15000){
    dataFile.close();
    digitalWrite(PIN_LED1,LOW);
    logging = false;
    digitalWrite(PIN_LED1,HIGH);
  } 

}

void blinkLED(char pin, char x, long d){
  for(char i = 0; i < x; i++){
    digitalWrite(pin,HIGH);
    delay(d);
    digitalWrite(pin,LOW);
    delay(d);
  }
}










