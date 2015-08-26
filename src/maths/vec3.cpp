#include "vec3.h"

namespace Glow { namespace maths {

    vec3& vec3::add(const vec3& other){

        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    vec3& vec3::subtract(const vec3& other){

        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    vec3& vec3::multiply(const vec3& other){

        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    vec3& vec3::divide(const vec3& other){

        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }


    vec3& vec3::add(float other){

        x += other;
        y += other;
        z += other;
        return *this;
    }

    vec3& vec3::subtract(float other){
        x -= other;
        y -= other;
        z -= other;
        return *this;
    }

    vec3& vec3::multiply(float other){
        x *= other;
        y *= other;
        z *= other;
        return *this;
    }

    vec3& vec3::divide(float other){
        x /= other;
        y /= other;
        z /= other;
        return *this;
    }


    vec3& vec3::add(float _x, float _y, float _z){
        x += _x;
        y += _y;
        z += _z;
        return *this;
    }

    vec3& vec3::subtract(float _x, float _y, float _z){
        x -= _x;
        y -= _y;
        z -= _z;
        return *this;
    }

    vec3& vec3::multiply(float _x, float _y, float _z){
        x *= _x;
        y *= _y;
        z *= _z;
        return *this;
    }

    vec3& vec3::divide(float _x, float _y, float _z){
        x /= _x;
        y /= _y;
        z /= _z;
        return *this;
    }


    bool vec3::equals(const vec3& other){
        return x == other.x && y == other.y && z == other.z;
    }

    vec3& operator+(vec3& left, const vec3& right){
        return left.add(right);
    }

    vec3& operator-(vec3& left, const vec3& right){
        return left.subtract(right);
    }

    vec3& operator*(vec3& left, const vec3& right){
        return left.multiply(right);
    }

    vec3& operator/(vec3& left, const vec3& right){
        return left.divide(right);
    }


    vec3& vec3::operator+=(const vec3& other){
        return add(other);
    }

    vec3& vec3::operator-=(const vec3& other){
        return subtract(other);
    }

    vec3& vec3::operator*=(const vec3& other){
        return multiply(other);
    }

    vec3& vec3::operator/=(const vec3& other) {
        return divide(other);
    }

    bool vec3::operator==(const vec3& other) {
        return equals(other);
    }

    bool vec3::operator!=(const vec3& other) {
        return !equals(other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec3& vector){

        stream << "vec3: (" << vector.x << "|" << vector.y << "|" << vector.z << ")";
        return stream;
    }

}}
