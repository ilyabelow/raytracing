//
// Created by ilyabelow on 17/06/2022.
//

#ifndef RAYTRACING_TRANSFORMS_H
#define RAYTRACING_TRANSFORMS_H

#include <functional>
#include "primitives/Point.h"
#include "primitives/Direction.h"

typedef std::function<Point(Point)> Transform;

Transform id();

Transform shift(float x, float y);

Transform constraint(float x_start, float x_end);

Transform rotate(float phi);

Transform rotateSphere(Direction direction);

Transform fromSpherical();

Transform fromCylindrical();

#endif //RAYTRACING_TRANSFORMS_H
