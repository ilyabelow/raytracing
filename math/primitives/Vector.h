//
// Created by ilyabelow on 29.05.2022.
//

#ifndef RAYTRACING_VECTOR_H
#define RAYTRACING_VECTOR_H

#include <cmath>

struct Vector {
    Vector() = default;

    Vector(float x, float y, float z);

    [[nodiscard]] bool isZero() const;

    Vector operator+(const Vector &rhs) const;
    Vector &operator+=(const Vector &rhs) &;

    Vector operator-(const Vector &rhs) const;
    Vector &operator-=(const Vector &rhs) &;
    Vector operator-() const;

    Vector &operator*=(float s);
    Vector operator*(float s) const;

    Vector &operator/=(float s);
    Vector operator/(float s) const;

    [[nodiscard]] float norm2() const;
    [[nodiscard]] float norm() const;
    [[nodiscard]] Vector normalize() const;

    [[nodiscard]] Vector cross(const Vector &rhs) const;
    [[nodiscard]] float dot(const Vector &rhs) const;

    [[nodiscard]] Vector rotate(const Vector &k, float theta) const;
    Vector &rotate_this(const Vector &k, float theta) &;

    float x;
    float y;
    float z;
};

Vector operator*(float s, const Vector &rhs);

#endif //RAYTRACING_VECTOR_H
