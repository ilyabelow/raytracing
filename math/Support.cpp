//
// Created by ilyabelow on 17/06/2022.
//

#include "Support.h"

float sqr(float x) {
    return x * x;
}

void normalize_angle(float& a) {
    while (a < -F_PI) {
        a += F_2_PI;
    }
    while (a > F_PI) {
        a -= F_2_PI;
    }
}
float operator ""_o(unsigned long long int x) {
    return static_cast<float>(x) / 180.f * F_PI;
}

float operator ""_o(long double x) {
    return static_cast<float>(x) / 180.f * F_PI;
}
