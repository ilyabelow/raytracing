//
// Created by ilyabelow on 17/06/2022.
//

#ifndef RAYTRACING_BONDS_H
#define RAYTRACING_BONDS_H

#include <functional>
#include "primitives/Point.h"

typedef std::function<bool(Point)> Bound;

Bound all();

Bound circle(Point center, float r);

Bound circle(float r);

Bound lengthConstrain(float start, float end);

Bound square(float a);

#endif //RAYTRACING_BONDS_H
