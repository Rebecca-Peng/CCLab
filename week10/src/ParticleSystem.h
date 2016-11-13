//
//  ParticleSystem.hpp
//  cclab2
//
//  Created by pfy on 11/7/16.
//
//
#pragma once

#include "Particle.h"
#include "ofMain.h"


#include <stdio.h>

class ParticleSystem{
public:
    
    ParticleSystem(ofVec2f position);
    void update(ofVec2f force);
    void draw();
    
    vector<Particle>        mParticleList;
    
    ofVec2f                 mPosition;
    int                     mEmitRate;
    bool                    mIsAddingParticles;

};

