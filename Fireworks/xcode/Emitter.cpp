//
//  Emitter.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#include "Emitter.h"

Emitter::Emitter(ci::Vec2f loc) {
    mLoc = loc;
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        mParticles.push_back(Particle(mLoc));
    }
}

void Emitter::draw() {
    for (auto partIter = mParticles.begin(); partIter != mParticles.end(); ++partIter) {
        partIter->draw();
        
    }
}

void Emitter::update() {
    for (auto partIter = mParticles.begin(); partIter != mParticles.end(); ++ partIter) {
        if (partIter->isDead()) partIter = mParticles.erase(partIter);
        else partIter->update();
        
    }
}

bool Emitter::isDone() {
    return mParticles.size() == 0;
}