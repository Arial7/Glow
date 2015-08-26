#pragma once

#include <iostream>

namespace Glow { namespace maths {


struct vec3 {
    vec3() : x(0), y(0), z(0){};
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};
    vec3(vec3 &vc) : x(vc.x), y(vc.y), z(vc.z){};

    float x, y, z;

    vec3& add(const vec3& other);
    vec3& subtract(const vec3& other);
    vec3& multiply(const vec3& other);
    vec3& divide(const vec3& other);

    vec3& add(float other);
    vec3& subtract(float other);
    vec3& multiply(float other);
    vec3& divide(float other);

    vec3& add(float _x, float _y, float _z);
    vec3& subtract(float _x, float _y, float _z);
    vec3& multiply(float _x, float _y, float _z);
    vec3& divide(float _x, float _y, float _z);

    bool equals(const vec3& other);

    friend vec3& operator+(vec3& left, const vec3& right);
    friend vec3& operator-(vec3& left, const vec3& right);
    friend vec3& operator*(vec3& left, const vec3& right);
    friend vec3& operator/(vec3& left, const vec3& right);

    vec3& operator+=(const vec3& other);
    vec3& operator-=(const vec3& other);
    vec3& operator*=(const vec3& other);
    vec3& operator/=(const vec3& other);

    bool operator==(const vec3& other);
    bool operator!=(const vec3& other);

    friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);

};


}}
