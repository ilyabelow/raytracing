//
// Created by ilyabelow on 17/06/2022.
//

#include "Bonds.h"
#include "Support.h"

Bound all() {
    return [](Point) {return true;};
}
Bound circle(Point center, float r) {
    return [center, r](Point p) {return sqr(p.x-center.x) + sqr(p.y-center.y) < sqr(r);};
}

Bound circle(float r) {
    return [r](Point p) {return sqr(p.x) + sqr(p.y) < sqr(r);};
}

Bound lengthConstrain(float start, float end) {
    return [start, end](Point p) {return p.x > start && p.x < end;};
}
Bound square(float a) {
    return [a](Point p) {return p.x < a && p.y < a && p.x > -a && p.y > -a;};
}
