#include "vec4.h"

namespace Glow { namespace maths {

    vec4& vec4::add(const vec4& other){

        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    vec4& vec4::subtract(const vec4& other){

        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    vec4& vec4::multiply(const vec4& other){

        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }

    vec4& vec4::divide(const vec4& other){

        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;
        return *this;
    }


    vec4& vec4::add(float other){
        x += other;
        y += other;
        z += other;
        w += other;
        return *this;
    }

    vec4& vec4::subtract(float other){
        x -= other;
        y -= other;
        z -= other;
        w -= other;
        return *this;
    }

    vec4& vec4::multiply(float other){
        x *= other;
        y *= other;
        z *= other;
        w *= other;
        return *this;
    }

    vec4& vec4::divide(float other){
        x /= other;
        y /= other;
        z /= other;
        w /= other;
        return *this;
    }


    vec4& vec4::add(float _x, float _y, float _z, float _w){
        x += _x;
        y += _y;
        z += _z;
        w += _w;
        return *this;
    }

    vec4& vec4::subtract(float _x, float _y, float _z, float _w){
        x -= _x;
        y -= _y;
        z -= _z;
        w -= _w;
        return *this;
    }

    vec4& vec4::multiply(float _x, float _y, float _z, float _w){
        x *= _x;
        y *= _y;
        z *= _z;
        w *= _w;
        return *this;
    }

    vec4& vec4::divide(float _x, float _y, float _z, float _w){
        x /= _x;
        y /= _y;
        z /= _z;
        w /= _w;
        return *this;
    }


    bool vec4::equals(const vec4& other){
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    vec4& operator+(vec4& left, const vec4& right){
        return left.add(right);
    }

    vec4& operator-(vec4& left, const vec4& right){
        return left.subtract(right);
    }

    vec4& operator*(vec4& left, const vec4& right){
        return left.multiply(right);
    }

    vec4& operator/(vec4& left, const vec4& right){
        return left.divide(right);
    }


    vec4& vec4::operator+=(const vec4& other){
        return add(other);
    }

    vec4& vec4::operator-=(const vec4& other){
        return subtract(other);
    }

    vec4& vec4::operator*=(const vec4& other){
        return multiply(other);
    }

    vec4& vec4::operator/=(const vec4& other) {
        return divide(other);
    }

    bool vec4::operator==(const vec4& other) {
        return equals(other);
    }

    bool vec4::operator!=(const vec4& other) {
        return !equals(other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec4& vector){

        stream << "vec4: (" << vector.x << "," << vector.y << "," << vector.z
            << "," << vector.w << ")";
        return stream;
    }

}}
