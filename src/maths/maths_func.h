#pragma once

//defines common math functions, as well as math constants


#define PI 3.14159265358979323846

namespace Glow { namespace maths {

    float toRadians(float degrees){
        return degrees * (PI / 180.0f);
    }

}}
