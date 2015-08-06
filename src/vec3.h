#ifndef VEC3_H
#define VEC3_H

#include <math.h>

struct Vec3 {
	Vec3() : x(0), y(0), z(0){};
	Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};
    float x, y, z;
        

};

    static float dotProduct(Vec3 v1, Vec3 v2);

#endif
