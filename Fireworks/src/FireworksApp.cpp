#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "FireworksApp.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FireworksApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown(MouseEvent event);
    void mouseUp(MouseEvent event);
    void mouseDrag(MouseEvent event);
	void update();
	void draw();
    
private:
    ParticleSystem mPartSystem;
    bool mClicked;
    MouseEvent mLastEvent;
};

void FireworksApp::prepareSettings(Settings *settings) {
	settings->setWindowSize(1000, 800);
	settings->setFrameRate(60.0f);
}

void FireworksApp::setup() {
    mPartSystem = ParticleSystem();
}

void FireworksApp::mouseDown(MouseEvent event) {
    mClicked = true;
    mPartSystem.mouseDown(event);
    mLastEvent = event;
}

void FireworksApp::mouseUp(MouseEvent event) {
    mClicked = false;
}

void FireworksApp::mouseDrag(MouseEvent event) {
    mPartSystem.mouseDrag(event);
    mLastEvent = event;
}

void FireworksApp::update() {
    mPartSystem.update();
    if (mClicked) mouseDown(mLastEvent);
    
    printf("%.2f FPS\n", getAverageFps());
}

void FireworksApp::draw() {
    mPartSystem.draw();
}

CINDER_APP_NATIVE(FireworksApp, RendererGl)
