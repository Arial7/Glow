#include "vec2.h"

namespace Glow {

    Vec2& Vec2::add(const Vec2& other){

        x += other.x;
        y += other.y;

        return *this;

    }

    Vec2& Vec2::subtract(const Vec2& other){

        x -= other.x;
        y -= other.y;

        return *this;
    }

    Vec2& Vec2::multiply(const Vec2& other){

        x *= other.x;
        y *= other.y;

        return *this;
    }

    Vec2& Vec2::divide(const Vec2& other){

        x /= other.x;
        y /= other.y;

        return *this;
    }


    Vec2& Vec2::add(float other){

        x += other;
        y += other;

        return *this;

    }

    Vec2& Vec2::subtract(float other){

        x -= other;
        y -= other;

        return *this;

    }

    Vec2& Vec2::multiply(float other){

        x *= other;
        y *= other;

        return *this;

    }

    Vec2& Vec2::divide(float other){

        x /= other;
        y /= other;

        return *this;

    }


    Vec2& Vec2::add(float _x, float _y){

        x += _x;
        y += _y;
        return *this;
    }

    Vec2& Vec2::subtract(float _x, float _y){

        x -= _x;
        y -= _y;
        return *this;
    }

    Vec2& Vec2::multiply(float _x, float _y){

        x *= _x;
        y *= _y;
        return *this;
    }

    Vec2& Vec2::divide(float _x, float _y){

        x /= _x;
        y /= _y;
        return *this;
    }


    bool Vec2::equals(const Vec2& other){
        return x == other.x && y == other.y;
    }

    Vec2& operator+(Vec2& left, const Vec2& right){
        return left.add(right);
    }

    Vec2& operator-(Vec2& left, const Vec2& right){
        return left.subtract(right);
    }

    Vec2& operator*(Vec2& left, const Vec2& right){
        return left.multiply(right);
    }

    Vec2& operator/(Vec2& left, const Vec2& right){
        return left.divide(right);
    }


    Vec2& Vec2::operator+=(const Vec2& other){
        return add(other);
    }

    Vec2& Vec2::operator-=(const Vec2& other){
        return subtract(other);
    }

    Vec2& Vec2::operator*=(const Vec2& other){
        return multiply(other);
    }

    Vec2& Vec2::operator/=(const Vec2& other) {
        return divide(other);
    }

    bool Vec2::operator==(const Vec2& other) {
        return equals(other);
    }

    bool Vec2::operator!=(const Vec2& other) {
        return !equals(other);
    }

    std::ostream& operator<<(std::ostream& stream, const Vec2& vector){

        stream << "Vec2: (" << vector.x << "|" << vector.y << ")";
        return stream;

    }


}
