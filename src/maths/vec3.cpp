#include "vec3.h"

namespace Glow {

    Vec3& Vec3::add(const Vec3& other){

        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3& Vec3::subtract(const Vec3& other){

        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3& Vec3::multiply(const Vec3& other){

        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    Vec3& Vec3::divide(const Vec3& other){

        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }


    Vec3& Vec3::add(float other){

        x += other;
        y += other;
        z += other;
        return *this;
    }

    Vec3& Vec3::subtract(float other){
        x -= other;
        y -= other;
        z -= other;
        return *this;
    }

    Vec3& Vec3::multiply(float other){
        x *= other;
        y *= other;
        z *= other;
        return *this;
    }

    Vec3& Vec3::divide(float other){
        x /= other;
        y /= other;
        z /= other;
        return *this;
    }


    Vec3& Vec3::add(float _x, float _y, float _z){
        x += _x;
        y += _y;
        z += _z;
        return *this;
    }

    Vec3& Vec3::subtract(float _x, float _y, float _z){
        x -= _x;
        y -= _y;
        z -= _z;
        return *this;
    }

    Vec3& Vec3::multiply(float _x, float _y, float _z){
        x *= _x;
        y *= _y;
        z *= _z;
        return *this;
    }

    Vec3& Vec3::divide(float _x, float _y, float _z){
        x /= _x;
        y /= _y;
        z /= _z;
        return *this;
    }


    bool Vec3::equals(const Vec3& other){
        return x == other.x && y == other.y && z == other.z;
    }

    Vec3& operator+(Vec3& left, const Vec3& right){
        return left.add(right);
    }

    Vec3& operator-(Vec3& left, const Vec3& right){
        return left.subtract(right);
    }

    Vec3& operator*(Vec3& left, const Vec3& right){
        return left.multiply(right);
    }

    Vec3& operator/(Vec3& left, const Vec3& right){
        return left.divide(right);
    }


    Vec3& Vec3::operator+=(const Vec3& other){
        return add(other);
    }

    Vec3& Vec3::operator-=(const Vec3& other){
        return subtract(other);
    }

    Vec3& Vec3::operator*=(const Vec3& other){
        return multiply(other);
    }

    Vec3& Vec3::operator/=(const Vec3& other) {
        return divide(other);
    }

    bool Vec3::operator==(const Vec3& other) {
        return equals(other);
    }

    bool Vec3::operator!=(const Vec3& other) {
        return !equals(other);
    }

    std::ostream& operator<<(std::ostream& stream, const Vec3& vector){

        stream << "Vec3: (" << vector.x << "|" << vector.y << "|" << vector.z << ")";
        return stream;
    }



}
