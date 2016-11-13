//
//  a.cpp
//  cclab2
//
//  Created by pfy on 11/7/16.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f pos){

    mPosition = pos;
    mVelocity = ofVec2f(ofRandom(-2.f,2.f),ofRandom(-2.f,2.f));
    mAcceleration = ofVec2f(0,0);
    mLifeSpan = 255.f;
};



//---------------------------------------------
void Particle::resetForce(){
    mAcceleration *= 0 ;

};

//---------------------------------------------
void Particle::applyForce(ofVec2f force){
    mAcceleration += force;
    
};


//---------------------------------------------
void Particle::update(float multiplier){
    
    mVelocity += mAcceleration;
    // farther the particle is from the center, lesser the 
    mPosition += mVelocity *  multiplier * 2;
    
    if(mLifeSpan > 0){
    
        mLifeSpan -= 2.f;
    }

};


//---------------------------------------------
void Particle::draw(){
   
    ofDrawCircle(mPosition,3.f);
    standard = ofRandom(0,255);
    
    if(mLifeSpan > standard){
    
        ofSetColor(255,mLifeSpan - 80,0);
    }
    else if(mLifeSpan <=standard){
    
        ofSetColor(250,mLifeSpan + 80,8);

                   }
                   
    ofDrawCircle(mPosition,ofRandom(0,3) * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));
    ofDrawEllipse(mPosition, ofRandom(0,150) * ofMap(mLifeSpan, 0, 255.f, 0, 1.f), ofRandom(0,3) * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));
    ofDrawEllipse(mPosition, ofRandom(0,3) * ofMap(mLifeSpan, 0, 255.f, 0, 1.f), ofRandom(0,150) * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));

};

