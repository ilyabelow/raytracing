//
// Created by ilyabelow on 29.05.2022.
//

#include "Vector.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

Vector &Vector::operator+=(const Vector &rhs) &{
    x += rhs.x;
    y += rhs.y;
    z += rhs.y;
    return *this;
}

Vector Vector::operator+(const Vector &rhs) const {
    return {x + rhs.x, y + rhs.y, z + rhs.z};
}

Vector &Vector::operator-=(const Vector &rhs) &{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.y;
    return *this;
}

Vector Vector::operator-(const Vector &rhs) const {
    return {x - rhs.x, y - rhs.y, z - rhs.z};
}

Vector Vector::operator-() const {
    return -1 * (*this);
}

Vector &Vector::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

Vector Vector::operator*(float s) const {
    return {x * s, y * s, z * s};
}

Vector operator*(float s, const Vector &rhs) {
    return {s * rhs.x, s * rhs.y, s * rhs.z};
}

Vector &Vector::operator/=(float s) {
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

Vector Vector::operator/(float s) const {
    return {x / s, y / s, z / s};
}

Vector Vector::rotate(const Vector &k, float theta) const {
    return *this * std::cos(theta) +
        (k.cross(*this)) * std::sin(theta) +
        k * k.dot(*this) * (1 - std::cos(theta));
}

Vector &Vector::rotate_this(const Vector &k, float theta) &{
    *this = (*this).rotate(k, theta);
    return *this;
}


float Vector::norm2() const {
    return x * x + y * y + z * z;
}

Vector Vector::cross(const Vector &rhs) const {
    return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
}

float Vector::dot(const Vector &rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

float Vector::norm() const {
    return std::sqrt(norm2());
}

Vector Vector::normalize() const {
    return *this / norm();
}

bool Vector::isZero() const {
    return std::abs(x) < 0.0001 && std::abs(y) < 0.0001 && std::abs(z) < 0.0001;
}



