#pragma once

#include <iostream>

namespace Glow {


struct Vec3 {
    Vec3() : x(0), y(0), z(0){};
    Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};
    Vec3(Vec3 &vc) : x(vc.x), y(vc.y), z(vc.z){};

    float x, y, z;

    Vec3& add(const Vec3& other);
    Vec3& subtract(const Vec3& other);
    Vec3& multiply(const Vec3& other);
    Vec3& divide(const Vec3& other);

    Vec3& add(float other);
    Vec3& subtract(float other);
    Vec3& multiply(float other);
    Vec3& divide(float other);

    Vec3& add(float _x, float _y, float _z);
    Vec3& subtract(float _x, float _y, float _z);
    Vec3& multiply(float _x, float _y, float _z);
    Vec3& divide(float _x, float _y, float _z);

    bool equals(const Vec3& other);

    friend Vec3& operator+(Vec3& left, const Vec3& right);
    friend Vec3& operator-(Vec3& left, const Vec3& right);
    friend Vec3& operator*(Vec3& left, const Vec3& right);
    friend Vec3& operator/(Vec3& left, const Vec3& right);

    Vec3& operator+=(const Vec3& other);
    Vec3& operator-=(const Vec3& other);
    Vec3& operator*=(const Vec3& other);
    Vec3& operator/=(const Vec3& other);

    bool operator==(const Vec3& other);
    bool operator!=(const Vec3& other);

    friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);

};


}
