//
// Created by ilyabelow on 09.06.2022.
//

#include "Color.h"

float Color::fromHex(const char *c) {
    return static_cast<float>(resolveHexOneDigit(c[0]) * 16 + resolveHexOneDigit(c[1])) / 255.f;
}

uint8_t Color::resolveHexOneDigit(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    if ('A' <= c && c <= 'F') {
        return c - 'A' + 10;
    }
    if ('a' <= c && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0; // should never run
}

Color &Color::operator+=(const Color &rhs) {
    red += rhs.red;
    green += rhs.green;
    blue += rhs.blue;
    return *this;
}

Color Color::operator+(const Color &rhs) const {
    return {red + rhs.red, green + rhs.green, blue + rhs.blue};
}

Color Color::operator/(float s) const {
    return {red / s, green / s, blue / s};
}

Color Color::operator*(float s) const{
    return {red * s, green * s, blue * s};
}

Color operator*(float s, const Color &rhs) {
    return {rhs.getRed() * s, rhs.getGreen() * s, rhs.getBlue() * s};
}

