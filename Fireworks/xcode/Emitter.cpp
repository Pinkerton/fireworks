//
//  Emitter.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Emitter.h"

using namespace ci;

Emitter::Emitter(ci::Vec2f loc) {
    mLoc = loc;
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        mParticles.push_back(Particle(mLoc.x, mLoc.y));
    }
}

void Emitter::draw() {
    for (auto partIter = mParticles.begin(); partIter != mParticles.end(); ++partIter) {
        partIter->draw();
        
    }
}

void Emitter::update() {
    for (auto p = mParticles.begin(); p != mParticles.end(); ++ p) {
        if (p->getX() > app::getWindowWidth() || p->getY() > app::getWindowHeight() || p->isDead()) p = mParticles.erase(p);
        else p->update();
        
    }
}

bool Emitter::isDone() {
    return mParticles.size() == 0;
}