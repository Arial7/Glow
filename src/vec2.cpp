#include "vec2.h"

namespace Glow {
    float dotProduct(const Vec2 &v1, const Vec2 &v2){
        return (v1.x * v2.x + v1.y * v2.x);
    }
}
