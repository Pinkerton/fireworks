//
//  Emitter.cpp
//  Fireworks
//
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Utils.h"
#include "Emitter.h"
#include "ParticleSystem.h"

using namespace ci;

Emitter::Emitter(Vec2f loc) {
    Emitter(loc, false);
}

Emitter::Emitter(Vec2f loc, bool respawn) {
    mLoc = loc;
    mRespawn = respawn;
    Vec3f baseColor = Utils::randHSV();
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        mParticles.push_back(Particle(mLoc.x, mLoc.y, baseColor));
    }
}

void Emitter::draw() {
    for (auto p = mParticles.begin(); p != mParticles.end(); ++p) p->draw();
}

void Emitter::update() {
    for (auto p = mParticles.begin(); p != mParticles.end(); ++ p) {
        if (p->getX() > app::getWindowWidth() || p->getY() > app::getWindowHeight() || p->isDead()) p = mParticles.erase(p);
        else {
            if (p->shouldEmit()) ParticleSystem::addEmitter(p->getLoc());
            p->update();
        }
    }
}

bool Emitter::isDone() { return mParticles.size() == 0; }

Vec2f Emitter::getLoc() { return mLoc; }

bool Emitter::shouldRespawn() { return mRespawn; }
