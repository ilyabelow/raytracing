//
// Created by ilyabelow on 29.05.2022.
//
#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Solid.h"
#include "../Support.h"

class Sphere : public Solid {

public:
    Sphere(Vector r0, float radius, Direction up) : r0(r0),
                                                    radius(radius),
                                                    radius2(radius * radius),
                                                    up(up) {}
    Sphere(Vector r0, float radius) : Sphere(r0, radius, {0, -90_o, 0}) {}

    std::optional<float> intersect(const Line &line) override {
        Vector rd = line.r0 - r0;
        float D = sqr(rd.dot(line.a)) - (rd.norm2() - radius2);
        if (D < 0) {
            return {};
        }
        float rd_dot_a = rd.dot(line.a);
        float sqrt_D = std::sqrt(D);
        float t1 = -rd_dot_a - sqrt_D;
        float t2 = -rd_dot_a + sqrt_D;

        if (t1 > 0 && bound(getCoord(line.point(t1)))) {
            return {t1};
        }
        if (t2 > 0 && bound(getCoord(line.point(t2)))) {
            return {t2};
        }
        return {};
    }

    Point getCoord(const Vector &r) override {
        Vector on_sphere = (r - r0) / radius;
        Vector cross = up.toVector().cross({0, 0, 1});
        Vector v = on_sphere;
        if (!cross.isZero()) {
            v = on_sphere.rotate(cross, std::asin(cross.norm()));
        }
        float phi = std::asin(v.z);
        float theta = std::atan2(v.y, v.x) - up.roll;
        return {theta, phi};
    }

    Vector getNorm(const Vector &r) override {
        return (r - r0) / radius;
    }

    ~Sphere() override = default;
private:
    Vector r0;
    float radius;
    float radius2;
    Direction up;

};

#endif //RAYTRACING_SPHERE_H
