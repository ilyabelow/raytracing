//
// Created by ilyabelow on 29.05.2022.
//

#include "ImageSaver.h"


void ImageSaver::createHeader() {
    const uint32_t info_header_size = 40;
    const uint32_t header_size = 14 + info_header_size;
    const uint16_t bits_per_pixel = 8*bytes_per_pixel;
    const uint16_t planes = 1;
    uint32_t pixel_count = width * height;
    uint32_t bitmap_size = pixel_count * bits_per_pixel;
    uint32_t file_size = bitmap_size + header_size;
    // Header
    file << "BM";                                    // Signature
    file.write(bytes(file_size), 4);        // FileSize
    file.write(bytes(zero), 4);             // reserved
    file.write(bytes(header_size), 4);      // DataOffset
    // InfoHeader
    file.write(bytes(info_header_size), 4); // Size
    file.write(bytes(width), 4);            // Width
    file.write(bytes(height), 4);           // Height
    file.write(bytes(planes), 2);           // Planes
    file.write(bytes(bits_per_pixel), 2);   // Planes
    file.write(bytes(zero), 4);             // Compression
    file.write(bytes(zero), 4);             // ImageSize
    file.write(bytes(zero), 4);             // XpixelsPerM
    file.write(bytes(zero), 4);             // YpixelsPerM
    file.write(bytes(zero), 4);             // Colors Used
    file.write(bytes(zero), 4);             // Important Colors
}

void ImageSaver::push(const Pixel& pixel) {
    if (closed) {
        return;
    }
    file.write(pixel.getBytes(), bytes_per_pixel);
    pixels_pushed++;
    pixels_in_line++;
    if (pixels_in_line == width) {
        if (width*bytes_per_pixel % 4 != 0) {
            file.write(bytes(zero), 4 - width*bytes_per_pixel % 4);
        }
        pixels_in_line = 0;
    }
    if (pixels_pushed == width * height) {
        file.close();
        closed = true;
    }
}