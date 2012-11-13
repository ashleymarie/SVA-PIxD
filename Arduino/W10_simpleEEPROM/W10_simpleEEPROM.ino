/*
 * EEPROM Read
 *
 * Reads the value of each byte of the EEPROM and prints it 
 * to the computer.
 * there are 512 bytes on the UNO 328 chip
 * This example code is in the public domain.
 */

#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
String message = "nuggest of wisdom";
int strLen;

boolean writeExample = false; // otherwise doing read example

void setup()
{
  // initialize serial and wait for port to open:
  Serial.begin(9600);

  if( writeExample){
    doWriteExample();
    Serial.println("ok, done writing");
  } 
  else {
    doReadExample();
     Serial.println("ok, done reading");
  }
}

void doWriteExample(){
  int addr = 0;
  for(char i = 0; i < message.length(); i++){
    char c = message.charAt(i);
    EEPROM.write(addr,c);
    Serial.print("wrote ");
    Serial.println(c);
    addr++;
  }
}

void doReadExample(){

  int addr = 0;

  for(char i = 0; i < message.length(); i++){
    char c = EEPROM.read(addr);

    Serial.print(addr);
    Serial.print("\t");
    Serial.print(c);
    Serial.println();

    // advance to the next address of the EEPROM
    addr++;

    delay(500);
  }
}

void loop()
{

}




