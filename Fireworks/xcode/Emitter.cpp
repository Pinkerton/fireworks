//
//  Emitter.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Utils.h"
#include "Emitter.h"

using namespace ci;

Emitter::Emitter(ci::Vec2f loc) {
    Emitter(loc, false);
}

Emitter::Emitter(ci::Vec2f loc, bool respawn) {
    mLoc = loc;
    mRespawn = respawn;
    // http://stackoverflow.com/a/43235
    Vec3f baseColor = Utils::randHSV();
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        mParticles.push_back(Particle(mLoc.x, mLoc.y, baseColor));
    }
}

void Emitter::draw() {
    for (auto p = mParticles.begin(); p != mParticles.end(); ++p) {
        p->draw();
        
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

Vec2f Emitter::getLoc() {
    return Vec2f(mLoc);
}

bool Emitter::shouldRespawn() {
    return mRespawn;
}