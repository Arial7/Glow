#include "vec2.h"

namespace Glow { namespace maths {

    vec2& vec2::add(const vec2& other){

        x += other.x;
        y += other.y;

        return *this;

    }

    vec2& vec2::subtract(const vec2& other){

        x -= other.x;
        y -= other.y;

        return *this;
    }

    vec2& vec2::multiply(const vec2& other){

        x *= other.x;
        y *= other.y;

        return *this;
    }

    vec2& vec2::divide(const vec2& other){

        x /= other.x;
        y /= other.y;

        return *this;
    }


    vec2& vec2::add(float other){

        x += other;
        y += other;

        return *this;

    }

    vec2& vec2::subtract(float other){

        x -= other;
        y -= other;

        return *this;

    }

    vec2& vec2::multiply(float other){

        x *= other;
        y *= other;

        return *this;

    }

    vec2& vec2::divide(float other){

        x /= other;
        y /= other;

        return *this;

    }


    vec2& vec2::add(float _x, float _y){

        x += _x;
        y += _y;
        return *this;
    }

    vec2& vec2::subtract(float _x, float _y){

        x -= _x;
        y -= _y;
        return *this;
    }

    vec2& vec2::multiply(float _x, float _y){

        x *= _x;
        y *= _y;
        return *this;
    }

    vec2& vec2::divide(float _x, float _y){

        x /= _x;
        y /= _y;
        return *this;
    }


    bool vec2::equals(const vec2& other){
        return x == other.x && y == other.y;
    }

    vec2& operator+(vec2& left, const vec2& right){
        return left.add(right);
    }

    vec2& operator-(vec2& left, const vec2& right){
        return left.subtract(right);
    }

    vec2& operator*(vec2& left, const vec2& right){
        return left.multiply(right);
    }

    vec2& operator/(vec2& left, const vec2& right){
        return left.divide(right);
    }


    vec2& vec2::operator+=(const vec2& other){
        return add(other);
    }

    vec2& vec2::operator-=(const vec2& other){
        return subtract(other);
    }

    vec2& vec2::operator*=(const vec2& other){
        return multiply(other);
    }

    vec2& vec2::operator/=(const vec2& other) {
        return divide(other);
    }

    bool vec2::operator==(const vec2& other) {
        return equals(other);
    }

    bool vec2::operator!=(const vec2& other) {
        return !equals(other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec2& vector){

        stream << "vec2: (" << vector.x << "|" << vector.y << ")";
        return stream;

    }


}}
