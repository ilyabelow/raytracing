//
// Created by ilyabelow on 29.05.2022.
//

#ifndef RAYTRACING_LINE_H
#define RAYTRACING_LINE_H

#include "Vector.h"

struct Line {
    Vector r0;
    Vector a;

    Line(const Vector& r0, const Vector& a): r0(r0), a(a / a.norm()) {}

    [[nodiscard]] Vector point(float t) const{
        return r0 + t * a;
    }

    [[nodiscard]] Line advance(float t) const {
        return {point(t), a};
    }
};

#endif //RAYTRACING_LINE_H
