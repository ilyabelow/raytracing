//
// Created by ilyabelow on 31.05.2022.
//

#include "Texture.h"
#include <cmath>

Color Squares::getColorInt(float x, float y) {
    if (static_cast<int>(std::abs(std::floor(x * freq1))) % 2 +
        static_cast<int>(std::abs(std::floor(y * freq2))) % 2 == 1) {
        return color1;
    }
    return color2;
}


Squares::Squares(Color color1, Color color2, float freq1, float freq2) :
        color1(color1),
        color2(color2),
        freq1(freq1),
        freq2(freq2) {}

Squares::Squares(Color color1, Color color2, float freq) : Squares(color1, color2, freq, freq) {}

Squares::Squares(Color color1, Color color2) : Squares(color1, color2, 1, 1) {

}

Color SolidColor::getColorInt(float x, float y) {
    return color;
}

SolidColor::SolidColor(Color color) : color(color) {

}

Color Gradient::getColorInt(float, float y) {
    if (y < start) {
        return color1;
    }
    if (y > finish) {
        return color2;
    }
    float t = (y - finish) / (start - finish);
    return color1 * t + color2 * (1 - t);

}

Gradient::Gradient(Color color1, Color color2, float start, float finish) :
        color1(color1),
        color2(color2),
        start(start),
        finish(finish) {}


Texture *blankTexture() {
    return new Squares(PURPLE, BLACK);
}

