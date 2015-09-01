#pragma once

//this header defines common math functions, as well as math constants

#include <math.h>

#define PI 3.14159265358979323846

namespace Glow { namespace maths {

    inline float toRadians(float degrees){
        return degrees * (PI / 180.0f);
    }

}}
