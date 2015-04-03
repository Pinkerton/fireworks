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

using namespace ci;
using namespace std;

class Emitter {
public:
    Emitter(Vec2f pos);
    Emitter(Vec2f pos, bool respawn);
    void draw();
    void update();
    bool isDone();
    bool shouldRespawn();
    Vec2f getLoc();
    
private:
    list<Particle> mParticles;
    Vec2f mLoc;
    bool mRespawn;
    
    int NUM_PARTICLES = 100;
};

#endif /* defined(__Fireworks__Emitter__) */
