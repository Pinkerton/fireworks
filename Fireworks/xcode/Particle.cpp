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
#include "utils.h"

using namespace ci;

Particle::Particle(float x, float y, Vec3f hsvColor) {
    mX = x;
    mY = y;
    mHSVColor = hsvColor;
    
    float randScalar = Rand::randFloat();

    mVX = Rand::randFloat(-15.0, 15.0);
    mVY = sqrtf(225 - mVX * mVX);
    mVY *= Rand::randBool() ? -1 : 1;
    
    mVX *= randScalar;
    mVY *= randScalar;
    
    mLife = 1000;
    mRad = 5;
    mA = 0.8f;
}

void Particle::draw() {
    gl::color(Utils::toColor(Utils::hsvToRGB(mHSVColor)));
    gl::drawSolidCircle(Vec2f(mX, mY), mRad);
}

void Particle::update() {
    fade(1);
    mX += mVX;
    mY += mVY;
    mVY += mA;
}

bool Particle::isDead() {
    return mLife <= 0 || mHSVColor.z <= 0;
}

void Particle::fade(int time) {
    
    mLife -= time;
    mHSVColor.z -= .015;
}

float Particle::getX() { return mX; }

float Particle::getY() { return mY; }
