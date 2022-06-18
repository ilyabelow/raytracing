//
// Created by ilyabelow on 30.05.2022.
//

#ifndef RAYTRACING_PLANE_H
#define RAYTRACING_PLANE_H

#include "Solid.h"

class Plane : public Solid {

public:
    Plane(Vector v,
          Vector u,
          Vector r0) :r0(r0),
                      v(v.normalize()),
                      u(u.normalize()),
                      n(v.cross(u).normalize()) {}

    std::optional<float> intersect(const Line &line) override {
        float a_dot_n = line.a.dot(n);
        if (std::abs(a_dot_n) < 1e-5) { // Fine?
            return {};
        }
        float t = (r0 - line.r0).dot(n) / a_dot_n;
        if (t < 0) {
            return {};
        }
        if (!bound(getCoord(line.point(t) - r0))) {
            return {};
        }
        return {t};
    }

    Point getCoord(const Vector& r) override{
        return { (r - r0).dot(v), (r - r0).dot(u)};
    }

    Vector getNorm(const Vector &) override {
        return n;
    }

    ~Plane() override = default;
private:
    Vector n;
    Vector r0;
    Vector v;
    Vector u;
};


#endif //RAYTRACING_PLANE_H
