/*
* Check the L train status using the text on the 
 * http://istheltrainfucked.com website
 * Adam Harvey / SVA PIxD Week 09
 *
 * This code is in the public domain.
 */

/* 
 Text we want to find
 <section id="status">
 <h2>
 yup
 </h2>
 </section>
 */

import processing.serial.*;


Serial port;

PFont font;
String url = "http://istheltrainfucked.com/";
boolean trainStatus;
boolean loadedYet = false;

// non-blocking time check
long sendInterval = 2000;
long lastInterval;

void setup() {
  size(400, 400);

  // init serial
  String portName = null;

  try {
    portName = Serial.list()[4];
  } 
  catch(Exception e) {
    println("probably not plugged into a serial port?");
  }

  if ( portName != null) {
    port = new Serial(this, portName, 9600);
  }
  // GUI
  font = createFont("Arial", 60);
  textFont(font);
  textAlign(CENTER);
  ellipseMode(CENTER);
}


void draw() {

  background(0);


  if ( millis() - lastInterval > sendInterval) {
    println("check the train and send status to arduino");
    lastInterval = millis();
    trainStatus = getTrainStatus();
    loadedYet = true;

    // if YUP send 'Y'
    // if NOPE send 'N'
    if ( port != null ) {
      if ( trainStatus == true ) {
        port.write('Y');
      } 
      else {
        port.write('N');
      }
    }
  }

  // circle
  fill(150);
  ellipse(width/2, height/2, 200, 200);

  // draw the message (yup or nope);
  String s = "";
  if ( !loadedYet) {
    s = "WAIT";
  } 
  else {
    if ( trainStatus) {
      s = "YUP";
    } 
    else {
      s = "NOPE";
    }
  }

  fill(255);
  text(s, width/2, height/2+20);
}



// true = F&cked YUP, false = NOPE
boolean getTrainStatus() {
  String s = join( loadStrings( url ), "\n");

  String m[] = match(s, "yup");

  if ( m != null ) {
    // a match was found for the string "yup"
    println(m[0]);
    trainStatus = true;
  } 
  else {
    trainStatus = false;
  }

  return trainStatus;
}

