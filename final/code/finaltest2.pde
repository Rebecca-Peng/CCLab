import processing.serial.*;

import ddf.minim.*;
import ddf.minim.spi.*; // for AudioRecordingStream
import ddf.minim.ugens.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph

Minim minim;
TickRate rateControl;
FilePlayer filePlayer;
AudioOutput out;

String fileName = "Filthy.mp3";

double mAccelCurrent;
double mAccelLast;
float frequency;

int state0 = 0;
int state1 = 0;

int count = 0;
int pastpeak = 0;
int curpeak = 0;
int diff = 0;
int diff2 = 0;
int pastdiff = 0;

void setup () {
  // set the window size:
  size(1000, 400);

  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 9600);
  myPort.bufferUntil('\n');

  background(0);
  
   minim = new Minim(this);                        
   filePlayer = new FilePlayer( minim.loadFileStream(fileName) );
   filePlayer.loop();
  
   rateControl = new TickRate(1.f);

   out = minim.getLineOut();
   filePlayer.patch(rateControl).patch(out);
  
}
void draw () {
  //double oldtime = millis();

  while(myPort.available()>0){
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
 
    String nums[] = split(inString,',');  
    
    if(nums.length >= 8){
    int X = int(nums[0]);
    int Y = int(nums[1]);
    int Z = int(nums[2]);
  
    
    //println(X);
    //println(Y);
    //println(Z);
    
    count ++;
    state0 = state1;
    
    mAccelLast = mAccelCurrent;
    mAccelCurrent = Math.sqrt(X * X + Y * Y + Z * Z);
    //println(mAccelCurrent);
    if(mAccelCurrent > 1.628 * mAccelLast){
      
        state1 = 1;
        
      }
     else if (mAccelCurrent <= 1.628* mAccelLast && mAccelCurrent > 0.95 * mAccelLast){
      
       state1 = 0;
        
      }
     else{
     
       state1 = -1;
     }
     
     if(state0 != state1 && state1 == 1){
     
       pastpeak = curpeak;
       curpeak = count;
       pastdiff = diff;
       diff = curpeak - pastpeak;
       
     }
     //else{
     
     //  diff = pastdiff;
       
     //}
     if(diff > 10){
     diff2 = diff;
     println(diff2);
       }
     frequency = float(diff2);
     float rate = map(frequency,10,100,2.1f,0.1f);
     //float rate = 0.009 * frequency * frequency + 0.91;
     rateControl.value.setLastValue(rate);
        }
      }
    }
    //double newtime = millis();
    //println(newtime-oldtime);
  }