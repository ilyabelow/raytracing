//
// Created by ilyabelow on 30.05.2022.
//

#ifndef RAYTRACING_TEXTURE_H
#define RAYTRACING_TEXTURE_H

#include "Color.h"
#include "../math/primitives/Direction.h"
#include "../math/primitives/Point.h"
#include "../math/Transforms.h"

#include <functional>
#include <utility>

class Texture {
private:
    std::function<Point(Point)> transform = id();
protected:
    virtual Color getColorInt(float x, float y) = 0;
public:
    virtual Texture *addTransform(const Transform &f) final {
        transform = [transform = this->transform, f](const Point &p) -> Point { return f(transform(p)); };
        return this;
    }

    virtual Color getColor(float x, float y) final {
        Point p = transform({x, y});
        return getColorInt(p.x, p.y);
    }

    virtual ~Texture() = default;
};

class SolidColor : public Texture {
private:
    Color color;
    Color getColorInt(float x, float y) override;

public:
    explicit SolidColor(Color color);

    ~SolidColor() override = default;
};

Texture *blankTexture();

class Squares : public Texture {
private:
    Color color1;
    Color color2;
    float freq1;
    float freq2;

    Color getColorInt(float x, float y) override;
public:
    Squares(Color color1, Color color2, float freq1, float freq2);

    Squares(Color color1, Color color2, float freq);

    Squares(Color color1, Color color2);

    ~Squares() override = default;
};

class Gradient : public Texture {
private:
    Color color1;
    Color color2;
    float start;
    float finish;

    Color getColorInt(float, float y) override;

public:
    Gradient(Color color1, Color color2, float start, float finish);

    ~Gradient() override = default;
};

#endif //RAYTRACING_TEXTURE_H
