//
// Created by ilyabelow on 01.06.2022.
//

#ifndef RAYTRACING_RENDERER_H
#define RAYTRACING_RENDERER_H

#include "Scene.h"
#include "Camera.h"
#include "ImageSaver.h"

#include <iostream>

class Renderer {

public:
    explicit Renderer(Scene *scene) : scene(scene) {}

    void render(const std::string &target);

    void render(const char *target);

private:
    float red_carry = 0;
    float green_carry = 0;
    float blue_carry = 0;

    Scene *scene;

    Color backdrop{};

    Color sendLine(Line line, int order);
    Pixel toPixel(const Color &color);
};

#endif //RAYTRACING_RENDERER_H
