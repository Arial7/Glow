#pragma once

#include <iostream>


namespace Glow {

    struct Vec2 {
        Vec2() : x(0), y(0){};
        Vec2(float _x, float _y) : x(_x), y(_y){};
        Vec2(const Vec2 &copy) : x(copy.x), y(copy.y){};

        float x, y;

        Vec2& add(const Vec2& other);
        Vec2& subtract(const Vec2& other);
        Vec2& multiply(const Vec2& other);
        Vec2& divide(const Vec2& other);

        Vec2& add(float other);
        Vec2& subtract(float other);
        Vec2& multiply(float other);
        Vec2& divide(float other);

        Vec2& add(float _x, float _y);
        Vec2& subtract(float _x, float _y);
        Vec2& multiply(float _x, float _y);
        Vec2& divide(float _x, float _y);

        bool equals(const Vec2& other);

        friend Vec2& operator+(Vec2& left, const Vec2& right);
        friend Vec2& operator-(Vec2& left, const Vec2& right);
        friend Vec2& operator*(Vec2& left, const Vec2& right);
        friend Vec2& operator/(Vec2& left, const Vec2& right);

        Vec2& operator+=(const Vec2& other);
        Vec2& operator-=(const Vec2& other);
        Vec2& operator*=(const Vec2& other);
        Vec2& operator/=(const Vec2& other);

        bool operator==(const Vec2& other);
        bool operator!=(const Vec2& other);

        friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

    };

}
