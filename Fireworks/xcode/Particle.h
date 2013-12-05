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

class Particle {
public:
    Particle(float x, float y);
    void draw();
    void update();
    bool isDead();
    void fade(int time);
    
    float getX();
    float getY();
    
private:
    int mLife;
    int mRad;
    
    float mX;
    float mY;
    float mVX;
    float mVY;
    float mA;
};

#endif /* defined(__Fireworks__Particle__) */
