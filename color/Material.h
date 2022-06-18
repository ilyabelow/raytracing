//
// Created by ilyabelow on 17/06/2022.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "../math/primitives/Line.h"

class Material {
private:
    float absorption = 1;
public:
    explicit Material(float absorption) : absorption(absorption) {}

    virtual Line bend(const Vector &n, const Line &line) const = 0;

    virtual float getAbsorption() final {
        return absorption;
    }

    virtual ~Material() = default;
};

Material *blankMaterial();

class SimpleMaterial : public Material {
public:
    SimpleMaterial() : Material(1) {}

    [[nodiscard]] Line bend(const Vector &n, const Line &line) const override;

    ~SimpleMaterial() override = default;
};

class Mirror : public Material {
public:
    Mirror() : Material(0) {}

    explicit Mirror(float alpha) : Material(alpha) {}

    [[nodiscard]] Line bend(const Vector &n, const Line &line) const override;
    ~Mirror() override = default;
};

class Translucent : public Material {
public:
    explicit Translucent(float alpha) : Material(alpha) {}

    [[nodiscard]] Line bend(const Vector &n, const Line &line) const override;
    ~Translucent() override = default;
};

class Refractive : public Material {
private:
    float n1, n2;
public:
    Refractive(float n1, float n2) : Material(0), n1(n1), n2(n2) {}

    [[nodiscard]] Line bend(const Vector &n, const Line &line) const override;

    ~Refractive() override = default;
};


#endif //RAYTRACING_MATERIAL_H
