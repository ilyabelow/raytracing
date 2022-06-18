//
// Created by ilyabelow on 31.05.2022.
//

#ifndef RAYTRACING_DIRECTION_H
#define RAYTRACING_DIRECTION_H


#include "Vector.h"

struct Direction {
    float yaw;
    float pitch;
    float roll;

    Direction(float yaw, float pitch, float roll) : yaw(yaw), pitch(pitch), roll(roll) {}

    Direction(float yaw, float pitch) : yaw(yaw), pitch(pitch), roll(0) {}

    [[nodiscard]] Vector toVector() const {
        return {std::cos(pitch)*std::cos(yaw), std::cos(pitch)* std::sin(yaw), std::sin(pitch)};
    }
};

#endif //RAYTRACING_DIRECTION_H
