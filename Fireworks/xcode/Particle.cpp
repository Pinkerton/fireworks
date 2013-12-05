//
//  Particle.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

using namespace ci;

Particle::Particle(Vec2f loc) {
    mLoc = loc;
    mDir = Rand::randVec2f();
    mVel = Vec2f(Rand::randFloat(5.0f), Rand::randFloat(5.0f));
    mLife = 10000;
    mRad = 10;
    mAcc = 0.1;
}

void Particle::draw() {
    gl::drawSolidCircle(mLoc, mRad);
}

void Particle::update() {
    fade(1);
    mDir += mVel;
    mVel += mAcc;
    printf("%f, %f\n", mDir.x, mDir.y);
    mLoc += mDir * mVel;
    //mVel -= mAcc;
}

bool Particle::isDead() {
    return mLife <= 0;
}

void Particle::fade(int time) {
    mLife -= time;
}
