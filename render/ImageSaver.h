//
// Created by ilyabelow on 29.05.2022.
//

#ifndef RAYTRACING_IMAGESAVER_H
#define RAYTRACING_IMAGESAVER_H

#include <vector>
#include <cstdint>
#include <fstream>
#include "Pixel.h"

const uint16_t bytes_per_pixel = 3;
const uint32_t zero = 0;

class ImageSaver {
public:
    ImageSaver(int width, int height, const char * filename): width(width), height(height) {
        file.open (filename, std::ios_base::out);
        createHeader();
    }

    ~ImageSaver() {
        if (!closed) {
            file.close();
        }
    }

    void push(const Pixel& pixel);

    bool isClosed() const { return closed; }

private:
    bool closed = false;

    int pixels_pushed = 0;
    int pixels_in_line = 0;

    std::ofstream file;
    uint32_t width;
    uint32_t height;


    template<class T>
    const char *bytes(const T &n) {
        return reinterpret_cast<const char *>(&n);
    }

    void createHeader();
};


#endif //RAYTRACING_IMAGESAVER_H
