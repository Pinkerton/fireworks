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
	void mouseDown(MouseEvent event);
    void mouseDrag(MouseEvent event);
	void update();
	void draw();
    std::list<Emitter> emitters;
};

void FireworksApp::prepareSettings(Settings *settings) {
	settings->setWindowSize(1000, 800);
	settings->setFrameRate(60.0f);
}

void FireworksApp::setup() {
}

void FireworksApp::mouseDown(MouseEvent event) {
    emitters.push_back(Emitter(event.getPos(), true));
}

void FireworksApp::mouseDrag(MouseEvent event) {
    mouseDown(event);
}

void FireworksApp::update() {
    for (auto e = emitters.begin(); e != emitters.end(); ++e) {
        e->update();
        if (e->isDone()) {
            if (e->shouldRespawn()) emitters.push_back(Emitter(e->getLoc()));
            e = emitters.erase(e);
        }
    }
    //printf("%.2f FPS\n", getAverageFps());
}

void FireworksApp::draw() {
	gl::clear(Color(0, 0, 0));
    for (auto e = emitters.begin(); e != emitters.end(); ++e) {
        e->draw();
    }
}

CINDER_APP_NATIVE( FireworksApp, RendererGl )
