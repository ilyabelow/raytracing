//
// Created by ilyabelow on 29.05.2022.
//

#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H

#include <cstdint>


class Color {
public:
    Color() = default;

    Color(float red, float green, float blue) : red(red), green(green), blue(blue) {}

    Color(const char *code) noexcept: Color(fromHex(code), fromHex(code + 2), fromHex(code + 4)) {}

    Color &operator+=(const Color &rhs);

    Color operator+(const Color &rhs) const;

    Color operator/(float s) const;

    Color operator*(float s) const;

    [[nodiscard]] float getRed() const {
        return red;
    }

    [[nodiscard]] float getGreen() const {
        return green;
    }

    [[nodiscard]] float getBlue() const {
        return blue;
    }

private:
    float red;
    float blue;
    float green;

    static uint8_t resolveHexOneDigit(char c);

    static float fromHex(const char *c);

};

Color operator*(float s, const Color &rhs);



const Color WHITE = "FFFFFF";
const Color BLACK = "000000";

const Color RED = "FF0000";
const Color GREEN = "00FF00";
const Color BLUE = "0000FF";

const Color YELLOW = "FFFF00";
const Color PURPLE = "FF00FF";

#endif //RAYTRACING_COLOR_H
