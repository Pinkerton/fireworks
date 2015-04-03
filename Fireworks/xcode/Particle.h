//
//  Particle.h
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#ifndef __Fireworks__Particle__
#define __Fireworks__Particle__

#include <iostream>

using namespace ci;

class Particle {
public:
    Particle(float x, float y, Vec3f hsvColor, float explosionRadius);
    void draw();
    void update();
    bool shouldEmit();
    bool isDead();
    void fade();
    
    Vec2f getLoc();
    float getX();
    float getY();
    
private:
    int mRad;
    
    float mX;
    float mY;
    float mVX;
    float mVY;
    float mA;
    
    bool mEmitted;
    
    ci::Vec3f mHSVColor;
};

#endif /* defined(__Fireworks__Particle__) */

