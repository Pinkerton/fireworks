//
//  Emitter.h
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#ifndef __Fireworks__Emitter__
#define __Fireworks__Emitter__

#include <iostream>

#include "Particle.h"

class Emitter {
public:
    Emitter(ci::Vec2f pos);
    Emitter(ci::Vec2f pos, bool respawn);
    void draw();
    void update();
    bool isDone();
    ci::Vec2f getLoc();
    bool shouldRespawn();
    
private:
    std::list<Particle> mParticles;
    ci::Vec2f mLoc;
    bool mRespawn;
    
    int NUM_PARTICLES = 100;
};

#endif /* defined(__Fireworks__Emitter__) */
