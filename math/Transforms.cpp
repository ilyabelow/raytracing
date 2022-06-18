//
// Created by ilyabelow on 17/06/2022.
//

#include "Transforms.h"
#include "Support.h"

std::function<Point(Point)> id() {
    return [](Point p) -> Point { return p; };
}

std::function<Point(Point)> shift(float x, float y) {
    return [x, y](Point p) -> Point { return {p.x + x, p.y + y}; };
}

std::function<Point(Point)> rotate(float phi) {
    return [phi](Point p) -> Point {
        float alpha = std::atan2(p.y, p.x) + phi;
        float r = std::sqrt(p.x * p.x + p.y * p.y);
        return {std::cos(alpha) * r, std::sin(alpha) * r};
    };
}

std::function<Point(Point)> rotateSphere(Direction direction) {
    return [direction](Point p) -> Point {
        Vector cross = direction.toVector().cross({0, 0, 1});
        Vector v = Direction(p.x * F_PI_2, p.y * F_PI_2).toVector().rotate(cross, std::asin(cross.norm()));

        float phi = std::asin(v.z);
        float theta = std::atan2(v.y, v.x) - direction.roll;
        return {theta / F_PI_2, phi / F_PI_2};
    };
}
Transform fromSpherical() {
    return [](Point p) -> Point {return {p.x/F_PI_2, p.y / F_PI_2};};
}
Transform fromCylindrical() {
    return [](Point p) -> Point {return {p.x, p.y / F_PI};};
}
