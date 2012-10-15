/**
 *  
 *
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[4];
  println(Serial.list());
  println(portName);
  myPort = new Serial(this, portName, 9600);
}

void draw() {
}

void keyPressed() {

  int num = int(key);
  if ( num > 47 && num < 58) {
    println("Sending: " + key +", value: " + num);
    myPort.write(key);
  } 
  else {
    println("Number out of range");
  }
}

