#pragma once

namespace Glow {
    
    struct Vec2 {
        Vec2() : x(0), y(0){};
        Vec2(float _x, float _y) : x(_x), y(_y){};
        Vec2(const Vec2 &copy) : x(copy.x), y(copy.y){};

        float x, y;
        static float dotProduct(const Vec2 &v1, const Vec2 &v2);
    };

}
