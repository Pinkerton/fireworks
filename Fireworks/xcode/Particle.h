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
    Particle(ci::Vec2f loc);
    void draw();
    void update();
    bool isDead();
    void fade(int time);
    
private:
    int mLife;
    ci::Vec2f mLoc;
    ci::Vec2f mDir;
    ci::Vec2f mVel;
    int mRad;
    float mAcc;
};

#endif /* defined(__Fireworks__Particle__) */

