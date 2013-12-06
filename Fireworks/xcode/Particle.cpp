//
//  Particle.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#include "Particle.h"
#include "Emitter.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "utils.h"

using namespace ci;

Particle::Particle(float x, float y, Vec3f hsvColor) {
    mX = x;
    mY = y;
    mHSVColor = hsvColor;
    
    float randScalar = Rand::randFloat();
    float vMax = 15.0;

    mVX = Rand::randFloat(-vMax, vMax);
    mVY = sqrtf((vMax * vMax) - mVX * mVX);
    mVY *= Rand::randBool() ? -1 : 1;
    
    mVX *= randScalar;
    mVY *= randScalar;
    
    mRad = 5;
    mA = 0.8f;
    mEmitted = false;
}

void Particle::draw() {
    gl::color(Utils::toColor(Utils::hsvToRGB(mHSVColor)));
    gl::drawSolidCircle(Vec2f(mX, mY), mRad);
}

void Particle::update() {
    fade();
    mX += mVX;
    mY += mVY;
    mVY += mA;
}

bool Particle::isDead() {
    return mHSVColor.z <= 0;
}

bool Particle::shouldEmit() {
    if (mHSVColor.z <= 0.7 && !mEmitted && Rand::randInt(0, 2000) == 555) {
        mEmitted = true;
        return true;
    }
    return false;
}

void Particle::fade() {
    mHSVColor.z -= .015;
}

Vec2f Particle::getLoc() { return Vec2f(mX, mY); }

float Particle::getX() { return mX; }

float Particle::getY() { return mY; }
