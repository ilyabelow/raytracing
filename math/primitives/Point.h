//
// Created by ilyabelow on 10.06.2022.
//

#ifndef RAYTRACING_POINT_H
#define RAYTRACING_POINT_H

#include <functional>
#include "Direction.h"

struct Point {
    float x;
    float y;

    Point(float x, float y) : x(x), y(y) {

    }
};

#endif //RAYTRACING_POINT_H
