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
    void mouseDrag(MouseEvent event);
	void update();
	void draw();
    
private:
    ParticleSystem mPartSystem;
};

void FireworksApp::prepareSettings(Settings *settings) {
	settings->setWindowSize(1000, 800);
	settings->setFrameRate(60.0f);
}

void FireworksApp::setup() {
    mPartSystem = ParticleSystem();
}

void FireworksApp::mouseDown(MouseEvent event) {
    mPartSystem.mouseDown(event);
}

void FireworksApp::mouseDrag(MouseEvent event) {
    mPartSystem.mouseDrag(event);
}

void FireworksApp::update() {
    mPartSystem.update();
    //printf("%.2f FPS\n", getAverageFps());
}

void FireworksApp::draw() {
    mPartSystem.draw();
}

CINDER_APP_NATIVE(FireworksApp, RendererGl)
