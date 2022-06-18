//
// Created by ilyabelow on 17/06/2022.
//

#ifndef RAYTRACING_CYLINDER_H
#define RAYTRACING_CYLINDER_H

#include "Solid.h"

class Cylinder : public Solid {
public:
    Cylinder(Vector r0, Direction a, float radius) :
        r0(r0),
        roll(a.roll),
        a(a.toVector()),
        radius(radius),
        radius2(sqr(radius)) {}

    std::optional<float> intersect(const Line &line) override {
        Vector c = a.cross(line.a);
        Vector b = a.cross(line.r0 - r0);
        float D = sqr(c.dot(b)) - c.norm2() * (b.norm2() - radius2);
        if (D < 0) {
            return {};
        }
        float D_sqrt = std::sqrt(D);
        float c_dot_b = c.dot(b);
        float t1 = (-c_dot_b - D_sqrt) / c.norm2();
        float t2 = (-c_dot_b + D_sqrt) / c.norm2();
        if (t1 > 0 && bound(getCoord(line.point(t1)))) {
            return {t1};
        }
        if (t2 > 0 && bound(getCoord(line.point(t2)))) {
            return {t2};
        }
        return {};
    }
    Point getCoord(const Vector &r) override {
        float t = a.dot(r - r0);
        Vector on_cylinder = r - (a * t + r0);
        Vector axis = a.cross({0, 0, 1});
        Vector in_circle = on_cylinder;
        if (!axis.isZero()) {
            in_circle = on_cylinder.rotate(axis.normalize(), std::asin(axis.norm()));
        }
        float yaw = std::atan2(a.y, a.x);
        float rot = std::atan2(in_circle.y, in_circle.x);
        if (yaw > 0) {
            rot += (F_PI - yaw);
        } else {
            rot -= (F_PI + yaw);
        }
        rot -= roll;
        normalize_angle(rot);
        return {t, rot};
    }

    Vector getNorm(const Vector &r) override {
        float t = a.dot(r - r0);
        return (r - (a * t + r0)) / radius;
    }

    ~Cylinder() override = default;

private:
    Vector r0;
    Vector a;
    float radius;
    float radius2;
    float roll;
};

#endif //RAYTRACING_CYLINDER_H
