#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Emitter.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FireworksApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    std::list<Emitter> emitters;
};

void FireworksApp::prepareSettings(Settings *settings)
{
	settings->setWindowSize( 800, 600 );
	settings->setFrameRate( 60.0f );
}

void FireworksApp::setup()
{
    
}

void FireworksApp::mouseDown( MouseEvent event )
{
    emitters.push_back(Emitter(event.getPos()));
}

void FireworksApp::update()
{
    for (auto emitIter = emitters.begin(); emitIter != emitters.end(); ++emitIter) {
        emitIter->update();
        if (emitIter->isDone()) emitIter = emitters.erase(emitIter);
    }
}

void FireworksApp::draw()
{
	gl::clear(Color(0, 0, 0));
    for (auto emitIter = emitters.begin(); emitIter != emitters.end(); ++emitIter) {
        emitIter->draw();
    }
}

CINDER_APP_NATIVE( FireworksApp, RendererGl )
