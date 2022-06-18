//
// Created by Ilia Belov on 29.05.2022.
//

#ifndef RAYTRACING_SOLID_H
#define RAYTRACING_SOLID_H

#include "../primitives/Line.h"
#include "../primitives/Vector.h"

#include "../../color/Color.h"
#include "../../color/Texture.h"
#include "../../color/Material.h"
#include "../Bonds.h"

#include <optional>

class Solid {
protected:
    Texture *texture = blankTexture();
    Material *material = blankMaterial();
    Bound bound = all();


public:
    virtual Solid *setTexture(Texture *t) final {
        delete texture;
        texture = t;
        return this;
    }

    virtual Solid *setMaterial(Material *m) final {
        delete material;
        material = m;
        return this;
    }

    virtual Solid *setBound(Bound &&b) final {
        bound = std::move(b);
        return this;
    }
    virtual float getAbsorption() final {
        return material->getAbsorption();
    }

    virtual Line bend(const Line &line) final {
        return material->bend(getNorm(line.r0), line);
    }

    virtual Color getColor(const Vector &r) final {
        Point p = getCoord(r);
        return texture->getColor(p.x, p.y);
    }

    virtual std::optional<float> intersect(const Line &line) = 0;

    virtual Vector getNorm(const Vector &r) = 0;

    virtual Point getCoord(const Vector& r) = 0;

    virtual ~Solid() {
        delete texture;
        delete material;
    }
};

#endif //RAYTRACING_SOLID_H
