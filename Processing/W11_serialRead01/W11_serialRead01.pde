/*
* Read in serial from Arduino, convert to usable values 
 * Nov. 19, 2012
 * SVA PIxD
 * This code is in the public domain
 *
 */

import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
String inString = ""; // raw serial input
int lf = 10;
int bgValue = 0;
PFont font;

void setup() 
{
  size(400, 400);

  String portName = Serial.list()[4];
  println(Serial.list() );

  myPort = new Serial(this, portName, 9600); // serial speed must be the same

  font = createFont("Arial", 48); 
  textFont(font);
  textAlign(CENTER);
}

void draw()
{
  background(bgValue);             // Set background to white
  int fillVal = (bgValue + 128) % 255;
  fill(  fillVal );
  text( inString, width/2, height/2);
}


void serialEvent(Serial p) { 
  String rawInput = p.readStringUntil(lf); // until new line character arrives
  if ( rawInput != null ) {
    inString = rawInput;
    println("From Arduino: " + inString);
    parseSerialInput( trim(inString) );
  }
} 

void parseSerialInput(String s) {
  // s is a string from 0 - 1023
  int si = int(s);
  bgValue = int( map( si, 0, 1023, 0, 255) );
  //println(s + ", " + si +", " + bgValue);
}

