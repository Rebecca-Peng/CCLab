//
//  ParticleSystem.cpp
//  cclab2
//
//  Created by pfy on 11/7/16.
//
//

#include "ParticleSystem.h"
ParticleSystem::ParticleSystem(ofVec2f position){
    mPosition          = position;
    mEmitRate          = 100;
    mIsAddingParticles = true;


};


//---------------------------------------------

void ParticleSystem::update(ofVec2f force){
    
    if(mIsAddingParticles){
      
        Particle particle(mPosition);
        mParticleList.push_back(particle);
        
    }
    
    
    for(int i = 0; i < mParticleList.size(); i++){
    
        ofVec2f diff = ofVec2f(abs(mParticleList[i].mPosition.x-mPosition.x), abs(mParticleList[i].mPosition.y - mPosition.y));
        
        
        mParticleList[i].resetForce();
        
        mParticleList[i].applyForce(force);
        mParticleList[i].update(ofMap(diff.length(),0,200,4,1));

        if(diff.length() >= ofRandom(200,400)){
        // stop adding particle if there is any particle's diff is higher than a certain length
            mIsAddingParticles = false;
            //erase this particle
            if (mParticleList.size() > 0){
            
                mParticleList.erase(mParticleList.begin() + i);
            }
        }
    }

};

//--------------------------------------------
void ParticleSystem::draw(){
    
    for(int i = 0; i< mParticleList.size();i ++){
    
        mParticleList[i].draw();
    }


};
