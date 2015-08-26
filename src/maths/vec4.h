#pragma once

#include <iostream>

namespace Glow { namespace maths {

    struct vec4 {

        vec4() : x(0), y(0), z(0), w(0){};
        vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w){};
        vec4(vec4 &vc) : x(vc.x), y(vc.y), z(vc.z), w(vc.w){};

        float x, y, z, w;

        vec4& add(const vec4& other);
        vec4& subtract(const vec4& other);
        vec4& multiply(const vec4& other);
        vec4& divide(const vec4& other);

        vec4& add(float other);
        vec4& subtract(float other);
        vec4& multiply(float other);
        vec4& divide(float other);

        vec4& add(float _x, float _y, float _z, float _w);
        vec4& subtract(float _x, float _y, float _z, float _w);
        vec4& multiply(float _x, float _y, float _z, float _w);
        vec4& divide(float _x, float _y, float _z, float _w);

        bool equals(const vec4& other);

        friend vec4& operator+(vec4& left, const vec4& right);
        friend vec4& operator-(vec4& left, const vec4& right);
        friend vec4& operator*(vec4& left, const vec4& right);
        friend vec4& operator/(vec4& left, const vec4& right);

        vec4& operator+=(const vec4& other);
        vec4& operator-=(const vec4& other);
        vec4& operator*=(const vec4& other);
        vec4& operator/=(const vec4& other);

        bool operator==(const vec4& other);
        bool operator!=(const vec4& other);

        friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
    };

}}
