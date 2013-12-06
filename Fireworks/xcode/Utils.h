//
//  Utils.h
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/5/13.
//
//

#ifndef __Fireworks__Utils__
#define __Fireworks__Utils__

#include <iostream>

class Utils {
public:
    static ci::Vec3f randRGB();
    static ci::Vec3f randHSV();
    static ci::Vec3f hsvToRGB(ci::Vec3f hsv);
    static float goldenRatio(float value);
    static ci::Color toColor(ci::Vec3f color);
};

#endif /* defined(__Fireworks__Utils__) */
