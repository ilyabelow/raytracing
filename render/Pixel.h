//
// Created by ilyabelow on 18/06/2022.
//

#ifndef RAYTRACING_PIXEL_H
#define RAYTRACING_PIXEL_H

struct Pixel {
    uint8_t color[3]{};

    Pixel(uint8_t red, uint8_t green, uint8_t blue) {
        color[0] = blue;
        color[1] = green;
        color[2] = red;
    }

    [[nodiscard]] const char *getBytes() const {
        return reinterpret_cast<const char *>(color);
    }
};

#endif //RAYTRACING_PIXEL_H
