#pragma once

#include <iostream>

namespace Glow {

    struct Vec4 {

        Vec4() : x(0), y(0), z(0), w(0){};
        Vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w){};
        Vec4(Vec4 &vc) : x(vc.x), y(vc.y), z(vc.z), w(vc.w){};

        float x, y, z, w;

        Vec4& add(const Vec4& other);
        Vec4& subtract(const Vec4& other);
        Vec4& multiply(const Vec4& other);
        Vec4& divide(const Vec4& other);

        Vec4& add(float other);
        Vec4& subtract(float other);
        Vec4& multiply(float other);
        Vec4& divide(float other);

        Vec4& add(float _x, float _y, float _z, float _w);
        Vec4& subtract(float _x, float _y, float _z, float _w);
        Vec4& multiply(float _x, float _y, float _z, float _w);
        Vec4& divide(float _x, float _y, float _z, float _w);

        bool equals(const Vec4& other);

        friend Vec4& operator+(Vec4& left, const Vec4& right);
        friend Vec4& operator-(Vec4& left, const Vec4& right);
        friend Vec4& operator*(Vec4& left, const Vec4& right);
        friend Vec4& operator/(Vec4& left, const Vec4& right);

        Vec4& operator+=(const Vec4& other);
        Vec4& operator-=(const Vec4& other);
        Vec4& operator*=(const Vec4& other);
        Vec4& operator/=(const Vec4& other);

        bool operator==(const Vec4& other);
        bool operator!=(const Vec4& other);

        friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);
    };

}
