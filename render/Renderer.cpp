//
// Created by ilyabelow on 17/06/2022.
//

#include "Renderer.h"

void Renderer::render(const char *target) {
    int width = scene->camera.screen.width;
    int height = scene->camera.screen.height;
    Gradient sky("074AFD", "AAE8FD", -height / 2, height / 2);
    ImageSaver im(width, height, target);
    for (int y = -height / 2; y < height / 2; y++) {
        for (int x = width / 2; x > -width / 2; x--) {
            backdrop = sky.getColor(x, y);
            Color c = sendLine(scene->camera.getLine(x, y), 0);
            im.push(toPixel(c));
        }
    }
}

Color Renderer::sendLine(Line line, int order) {
    if (order == 5) {
        return BLACK;
    }
    auto collision = scene->intersect(line);
    if (collision.collided()) {
        Vector point = line.point(collision.t);
        Solid *solid = collision.solid;
        Color color = solid->getColor(point);
        float alpha = solid->getAbsorption();

        if (alpha == 1) {
            return color;
        }
        Line bent = solid->bend(line.advance(collision.t));
        return color * alpha + sendLine(bent, order + 1) * (1 - alpha);
    }
    return backdrop;
}
Pixel Renderer::toPixel(const Color &color) {
    uint8_t grades = 255;
    uint8_t additional = 255 / grades;

    float red = color.getRed() * grades;
    float green = color.getGreen() * grades;
    float blue = color.getBlue() * grades;

    auto red_round = static_cast<uint8_t>(red);
    auto green_round = static_cast<uint8_t>(green);
    auto blue_round = static_cast<uint8_t>(blue);

    float red_rep = red - red_round;
    float green_rep = green - green_round;
    float blue_rep = blue - blue_round;

    if (red_rep + red_carry > 1) {
        red_carry = red_rep + red_carry - 1;
        red_round++;
    } else {
        red_carry += red_rep;
    }
    if (green_rep + green_carry > 1) {
        green_carry = green_rep + green_carry - 1;
        green_round++;
    } else {
        green_carry += green_rep;
    }
    if (blue_rep + blue_carry > 1) {
        blue_carry = blue_rep + blue_carry - 1;
        blue_round++;
    } else {
        blue_carry += blue_rep;

    }

    return {
        static_cast<uint8_t>(red_round * additional),
        static_cast<uint8_t>(green_round * additional),
        static_cast<uint8_t>(blue_round * additional)
    };
//        return {
//                static_cast<uint8_t>(color.getRed()*255),
//                static_cast<uint8_t>(color.getGreen()*255),
//                        static_cast<uint8_t>(color.getBlue()*255)
//        };
}
void Renderer::render(const std::string &target) {
    render(target.c_str());
}
