#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    mCircleRadius = 100.f;
//    ofSetCircleResolution(100.f);
//    mPos = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());
    mPos = ofVec2f(15.f, 15.f);
    mPos2 = ofVec2f(ofGetWindowWidth() * 0.1, ofGetWindowHeight() * 0.3-90);
    mFriction = 0.99f;
    mAcceleration = ofVec2f(0);
    mVelocity = ofVec2f(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    mVelocity *= mFriction;
    mPos2 += mVelocity;
    
    if(mPos2.x > ofGetWindowWidth()) mPos2.x = 0;
    if(mPos2.y > ofGetWindowHeight()) mPos2.y = 0;
    if(mPos2.x < 85) lose();
//    if(mPos2.x < mPos.x + 150 || mPos2.x > mPos.x + 220)
//    { if(mPos2.y > mPos.y + 230) lose();}
    if(mPos2.y < mPos.y + 120) lose();
    if(mPos2.x < mPos.x + 320 && mPos2.y > 460) lose();
    if(mPos2.x > 540 && mPos2.y > 440) win();
    
    
}

void ofApp::win(){
    ofSetColor(255,0,0);
//    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    printf("You Win!");
}

void ofApp::lose(){
    ofSetColor(0, 0, 0);
//    ofDrawBitmapString("a test of multiline text", 100,100);
    printf("You Lose!");
}


//--------------------------------------------------------------
float ofApp::calculateArea(float a ,float b){
    return a * b;
}
void ofApp::draw(){
    ofSetBackgroundColor(0, 0, 0);
//    ofDrawCircle(mPos, mCircleRadius + mVelocity.length() * 10.f);
//    ofSetColor(255.f, 0, 0);
//    ofDrawBitmapStringHighlight("x :" +  ofToString(mPos.x) + "y : " + ofToString(mPos.y), mPos.x + 10.f, mPos.y + 10.f);
    for (int i = 0; i <ofGetWindowWidth(); i++){
        ofDrawTriangle(mPos.x+40 * i,mPos.y+10,mPos.x + 40 * i -10,mPos.y-10,mPos.x+10 + 40 * i,mPos.y-10);
        ofDrawTriangle(mPos.x+40 * i+20,mPos.y+30,mPos.x + 40 * i +10,mPos.y+10,mPos.x+30 + 40 * i,mPos.y+10);
        ofDrawTriangle(mPos.x+40 * i,mPos.y+50,mPos.x + 40 * i -10,mPos.y+30,mPos.x+10 + 40 * i,mPos.y+30);
        ofDrawTriangle(mPos.x+40 * i+20,mPos.y+70,mPos.x + 40 * i +10,mPos.y+50,mPos.x+30 + 40 * i,mPos.y+50);
        
        ofDrawTriangle(mPos.x,mPos.y+50+40 * i,mPos.x -10,mPos.y+30+ 40 * i,mPos.x+10,mPos.y+30 + 40 * i);
    }
    
    for (int i = 0; i <10; i++){
        ofDrawTriangle(mPos.x,mPos.y+50+40 * i,mPos.x -10,mPos.y+30+ 40 * i,mPos.x+10,mPos.y+30 + 40 * i);
        
        ofDrawTriangle(mPos.x+40 * i,mPos.y+510,mPos.x + 40 * i -10 ,mPos.y+490,mPos.x+10 + 40 * i,mPos.y+490);
        ofDrawTriangle(mPos.x+500,mPos.y+50+40 * i,mPos.x +490,mPos.y+30+ 40 * i,mPos.x+510,mPos.y+30 + 40 * i);
    }
    
    for (int i = 0; i <5; i++){
        ofDrawTriangle(mPos.x+200,mPos.y+50+40 * i,mPos.x +190,mPos.y+30+ 40 * i,mPos.x+210,mPos.y+30 + 40 * i);
        ofDrawTriangle(mPos.x+330,mPos.y+340+40 * i,mPos.x +320,mPos.y+320+ 40 * i,mPos.x+340,mPos.y+320 + 40 * i);
        
    }
    ofDrawCircle(mPos2,50);

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
     if(key == 'a')
     {
         
         ofSetColor(0,255,255);
         ofFill();
         ofSetBackgroundColor(0, 255, 255);
       

     }
    
    if(key == 's')
    {
        
        ofSetColor(208,232,5);
        ofFill();
        ofSetBackgroundColor(208,232,5);
    }
    
    if(key == 'd')
    {
        
        ofSetColor(0,200,155);
        ofFill();
        ofSetBackgroundColor(0,200,155);
    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
//    cout << "positon" << ofVec2f(x, y) << endl;
//    mPos = ofVec2f(x,y);
//    cout << "positon" << ofVec2f(x, y) << endl;
      ofVec2f mousePos = ofVec2f(x,y);
      mAcceleration = mPos2 - mousePos;
    
      float vecLength = mAcceleration.length();
      mAcceleration = mAcceleration / vecLength;
    
      mVelocity += mAcceleration;
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
