//
//  ParticleSystem.h
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/5/13.
//
//

#ifndef __Fireworks__ParticleSystem__
#define __Fireworks__ParticleSystem__

#include <iostream>
#include <thread>
#include "Emitter.h"
#include "cinder/audio/Io.h"

using namespace ci;
using namespace ci::app;

class ParticleSystem {

public:
    void mouseDown(MouseEvent event);
    void mouseDrag(MouseEvent event);
    void update();
	void draw();
    
    static void addEmitter(Vec2f loc);

private:
    static std::list<Emitter> emitters;
    static std::list<thread> threads;
    static audio::SourceRef mAudioSource;
};

#endif /* defined(__Fireworks__ParticleSystem__) */
