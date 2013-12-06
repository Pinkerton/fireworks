//
//  Utils.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/5/13.
//
//

#include "cinder/Rand.h"
#include "Utils.h"

using namespace ci;

ci::Vec3f Utils::randRGB() {
    return hsvToRGB(randHSV());
}

ci::Vec3f Utils::randHSV() {
    // http://stackoverflow.com/a/43235
    // http://martin.ankerl.com/2009/12/09/how-to-create-random-colors-programmatically/
    float h = goldenRatio(Rand::randFloat(0.0, 360.0));
    float s = 0.5;
    float v = 0.95;
    // TODO: Define a type for storing these colors
    return Vec3f(h, s, v);
}

ci::Vec3f Utils::hsvToRGB(Vec3f hsv) {
    // http://en.wikipedia.org/wiki/HSL_and_HSV#Converting_to_RGB
    float h = hsv.x;
    float s = hsv.y;
    float v = hsv.z;
    
    float r1 = 0;
    float g1 = 0;
    float b1 = 0;
    
    float c = v * s;
    int h1 = h / 60;
    float x = c * (1 - abs(h1 % 2 - 1));
    
    if      (h1 >= 0 && h1 < 1) { r1 = c; g1 = x; b1 = 0; }
    else if (h1 >= 1 && h1 < 2) { r1 = x; g1 = c; b1 = 0; }
    else if (h1 >= 2 && h1 < 3) { r1 = 0; g1 = c; b1 = x; }
    else if (h1 >= 3 && h1 < 4) { r1 = 0; g1 = x; b1 = c; }
    else if (h1 >= 4 && h1 < 5) { r1 = x; g1 = 0; b1 = c; }
    else if (h1 >= 5 && h1 < 6) { r1 = c; g1 = 0; b1 = x; }
    
    float m = v - c;
    
    float r = r1 + m;
    float g = g1 + m;
    float b = b1 + m;
    
    return Vec3f(r, g, b);
}

float Utils::goldenRatio(float value) {
    float conjugate = 0.618033988749895;
    return value + std::fmod(value + conjugate, 1.0);
}

Color Utils::toColor(Vec3f color) {
    // color must be in RGB!
    return Color(color.x, color.y, color.z);
}
