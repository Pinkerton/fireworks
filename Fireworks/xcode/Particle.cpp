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

Particle::Particle(float x, float y) {
    mX = x;
    mY = y;
    mVX = Rand::randFloat(-5.0, 5.0);
    mVY = Rand::randFloat(-5.0, 5.0);
    printf("%f, %f\n", mVX, mVY);
    mLife = 10000;
    mRad = 10;
    mA = 0.1;
}

void Particle::draw() {
    gl::drawSolidCircle(Vec2f(mX, mY), mRad);
}

void Particle::update() {
    fade(1);
    mX += mVX;
    mY += mVY;
    mVY += mA;
    //printf("%f, %f\n", mX, mY);
}

bool Particle::isDead() {
    return mLife <= 0;
}

void Particle::fade(int time) {
    mLife -= time;
}

float Particle::getX() { return mX; }

float Particle::getY() { return mY; }
