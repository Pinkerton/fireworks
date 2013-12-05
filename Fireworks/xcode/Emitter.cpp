//
//  Emitter.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Emitter.h"

using namespace ci;

Emitter::Emitter(ci::Vec2f loc) {
    mLoc = loc;
    // http://stackoverflow.com/a/43235
    Color color = hsvToRGB(randHSV());
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        mParticles.push_back(Particle(mLoc.x, mLoc.y, color));
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

ci::Vec3f Emitter::randHSV() {
    // http://martin.ankerl.com/2009/12/09/how-to-create-random-colors-programmatically/
    float h = goldenRatio(Rand::randFloat(0.0, 360.0));
    float s = 0.5;
    float v = 0.95;
    return Vec3f(h, s, v);
}

ci::Color Emitter::hsvToRGB(Vec3f hsv) {
    // http://en.wikipedia.org/wiki/HSL_and_HSV#Converting_to_RGB
    float h = hsv.x;
    float s = hsv.y;
    float v = hsv.z;
    
    float r1 = 0;
    float g1 = 0;
    float b1 = 0;
    
    float c = v * s;
    int h1 = h / 60;
    float x = c * (1 - abs(h1 % 2 - 1));
    
    if      (h1 >= 0 && h1 < 1) { r1 = c; g1 = x; b1 = 0; }
    else if (h1 >= 1 && h1 < 2) { r1 = x; g1 = c; b1 = 0; }
    else if (h1 >= 2 && h1 < 3) { r1 = 0; g1 = c; b1 = x; }
    else if (h1 >= 3 && h1 < 4) { r1 = 0; g1 = x; b1 = c; }
    else if (h1 >= 4 && h1 < 5) { r1 = x; g1 = 0; b1 = c; }
    else if (h1 >= 5 && h1 < 6) { r1 = c; g1 = 0; b1 = x; }
    
    float m = v - c;
    
    float r = r1 + m;
    float g = g1 + m;
    float b = b1 + m;
    
    return Color(r, g, b);
}

float Emitter::rgbToOGL(float value) {
    float piece = 1.0 / 255;
    return value * piece;
}

float Emitter::goldenRatio(float value) {
    float conjugate = 0.618033988749895;
    return value + std::fmod(value + conjugate, 1.0);
}
