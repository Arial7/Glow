#include "vec4.h"

namespace Glow {

    Vec4& Vec4::add(const Vec4& other){

        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    Vec4& Vec4::subtract(const Vec4& other){

        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    Vec4& Vec4::multiply(const Vec4& other){

        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }

    Vec4& Vec4::divide(const Vec4& other){

        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;
        return *this;
    }


    Vec4& Vec4::add(float other){
        x += other;
        y += other;
        z += other;
        w += other;
        return *this;
    }

    Vec4& Vec4::subtract(float other){
        x -= other;
        y -= other;
        z -= other;
        w -= other;
        return *this;
    }

    Vec4& Vec4::multiply(float other){
        x *= other;
        y *= other;
        z *= other;
        w *= other;
        return *this;
    }

    Vec4& Vec4::divide(float other){
        x /= other;
        y /= other;
        z /= other;
        w /= other;
        return *this;
    }


    Vec4& Vec4::add(float _x, float _y, float _z, float _w){
        x += _x;
        y += _y;
        z += _z;
        w += _w;
        return *this;
    }

    Vec4& Vec4::subtract(float _x, float _y, float _z, float _w){
        x -= _x;
        y -= _y;
        z -= _z;
        w -= _w;
        return *this;
    }

    Vec4& Vec4::multiply(float _x, float _y, float _z, float _w){
        x *= _x;
        y *= _y;
        z *= _z;
        w *= _w;
        return *this;
    }

    Vec4& Vec4::divide(float _x, float _y, float _z, float _w){
        x /= _x;
        y /= _y;
        z /= _z;
        w /= _w;
        return *this;
    }


    bool Vec4::equals(const Vec4& other){
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    Vec4& operator+(Vec4& left, const Vec4& right){
        return left.add(right);
    }

    Vec4& operator-(Vec4& left, const Vec4& right){
        return left.subtract(right);
    }

    Vec4& operator*(Vec4& left, const Vec4& right){
        return left.multiply(right);
    }

    Vec4& operator/(Vec4& left, const Vec4& right){
        return left.divide(right);
    }


    Vec4& Vec4::operator+=(const Vec4& other){
        return add(other);
    }

    Vec4& Vec4::operator-=(const Vec4& other){
        return subtract(other);
    }

    Vec4& Vec4::operator*=(const Vec4& other){
        return multiply(other);
    }

    Vec4& Vec4::operator/=(const Vec4& other) {
        return divide(other);
    }

    bool Vec4::operator==(const Vec4& other) {
        return equals(other);
    }

    bool Vec4::operator!=(const Vec4& other) {
        return !equals(other);
    }

    std::ostream& operator<<(std::ostream& stream, const Vec4& vector){

        stream << "Vec4: (" << vector.x << "," << vector.y << "," << vector.z
            << "," << vector.w << ")";
        return stream;
    }



}
