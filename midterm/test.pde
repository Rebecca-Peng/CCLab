import processing.serial.*;
import ddf.minim.*;

AudioPlayer player1;
AudioPlayer player2;
Minim minim1;
Minim minim2;

int lf = 10;
String string = null;

float volume1 = 0;
float volume2 = 0;

Serial myPort;

void setup(){

  printArray(Serial.list());
  myPort = new Serial(this,Serial.list()[3],9600);
  string = myPort.readStringUntil(lf);
  
  size(512,200,P2D);
  minim1 = new Minim(this);
  player1 = minim1.loadFile("left.mp3",2048);
  player1.play();
  player1.loop();
  
  minim2 = new Minim(this);
  player2 = minim1.loadFile("right.mp3",2048);
  player2.play();
  player2.loop();
  
}

void draw(){

  while(myPort.available()>0){
  
     string = myPort.readStringUntil(lf);
     if(string !=null){
       println(string);
       String nums[] = split(string,',');
       
       println(nums[0]);
       println(nums[1]);
       int val1 = int(nums[0]);
       float a = (float) val1;
       println(a);
       int val2 = int(nums[1]);
       float b = (float) val2;
       println(b);
       //println(nums[1]);
       //volume1 = a * 0.5 -20;
       //volume2 = b * 0.5 - 20
        if(volume1>100){
        volume1 = 100;
        }
       volume1 = map(a,0,100,-20,30);
        if(volume2>100){
        volume2 = 100;
        }
       volume2 = map(b,0,100,-20,30);
       player1.setGain(volume1);
       player2.setGain(volume2);
       
     }
  }
  delay(100);
}