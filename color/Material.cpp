//
// Created by ilyabelow on 17/06/2022.
//

#include "Material.h"

Material *blankMaterial() {
    return new SimpleMaterial();
}

Line SimpleMaterial::bend(const Vector &n, const Line &line) const {
    return line; // Should never be called
}

Line Mirror::bend(const Vector &n, const Line &line) const {
    Vector n_eff = n;
    if (n.dot(-line.a) < 0) {
        n_eff = -n;
    }
    Vector cross = n_eff.cross(-line.a);
    float theta = std::asin(cross.norm());
    Vector new_a = (-line.a).rotate(cross.normalize(), -theta * 2);
    return {line.point(-0.0001), new_a};
}

Line Translucent::bend(const Vector &n, const Line &line) const {
    return line.advance(0.0001);
}
Line Refractive::bend(const Vector &n, const Line &line) const {
    float n_rel = n1 / n2;
    Vector n_eff = n;
    if (n.dot(-line.a) < 0) {
        n_rel = n2 / n1;
        n_eff = -n;
    }
    Vector cross = n_eff.cross(-line.a);
    float sin_theta1 = cross.norm();
    float theta1 = std::asin(sin_theta1);
    float theta2 = std::asin(std::min<float>(n_rel * sin_theta1, 1));
    Vector new_a = line.a.rotate(cross.normalize(), -(theta1 - theta2));
    return {line.point(0.0001), new_a};
}
