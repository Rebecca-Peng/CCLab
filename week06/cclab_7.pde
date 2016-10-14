import processing.serial.*;

Serial myPort;
int xPos = 1;
float inByte = 0;

PImage img;
int cellsize = 2;
int columns,rows;

void setup(){
  
  size(640,360,P3D);
  img = loadImage("fucked up.JPG");
  columns = img.width / cellsize;
  rows = img.height / cellsize;
  
  myPort = new Serial(this,Serial.list()[3],9600);
  myPort.bufferUntil('\n');
  
}

void draw(){
   
  background(0);
  for ( int i = 0; i< columns; i++){
    for(int j = 0; j< rows; j++){
      int x = i * cellsize + cellsize/2;
      int y = j * cellsize + cellsize/2;
      int loc = x + y*img.width;
      color c = img.pixels[loc];
      float z = (inByte/ float(width)) * brightness(img.pixels[loc]) - 20.0;
      pushMatrix();
      translate(x + 200, y + 100, z);
      fill(c, 204);
      noStroke();
      rectMode(CENTER);
      rect(0, 0, cellsize, cellsize);
      popMatrix();
    }
  }
}


void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // convert to an int and map to the screen height:
    inByte = float(inString);
    println(inByte);
    inByte = map(inByte, 0, 1023, 0, height);
  }
}