//
//  a.hpp
//  cclab2
//
//  Created by pfy on 11/7/16.
//
//
#pragma once


#include "ofMain.h"

class Particle{
public:
    
    Particle(ofVec2f pos);

    void resetForce();
    void applyForce(ofVec2f force);
    void update(float multiplier);
    void draw();
    
    ofVec2f mPosition, mVelocity, mAcceleration;
    float mLifeSpan;
    float standard;
    
};
