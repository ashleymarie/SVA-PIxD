import processing.serial.*;

Serial myPort;
int val;     

void setup() 
{
  size(200, 200);

  int portId = 4;
  String portName = Serial.list()[portId];

  myPort = new Serial(this, portName, 9600);
}

void draw()
{


  background(255);             // Set background to white
}

ex
void serialEvent( Serial serial) {
  // char lec = '\n';
  // int lei = 10;
   String s = serial.readStringUntil( '\n' );
  // String s = serial.readString();
  if ( s == null ) {
    // no thanks
  } 
  else {
    s = trim(s);
    println( s );
  }
}

