//
// Created by ilyabelow on 29.05.2022.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H


#include "../math/primitives/Vector.h"
#include "../math/primitives/Line.h"
#include "../math/primitives/Direction.h"

struct Screen {
    int width;
    int height;
};

class Camera {
public:
    const Screen screen;

    Camera(Vector pos, Direction dir, Screen screen, float zoom) :
            position(pos),
            screen(screen),
            step(1/zoom/screen.width),
            forward({1, 0, 0}),
            left({0, 1, 0}),
            up({0, 0, 1})
            {
        // theta
        left.rotate_this(up, dir.yaw);
        forward.rotate_this(up, dir.yaw);
        // phi
        up.rotate_this(left, dir.pitch);
        forward.rotate_this(left, dir.pitch);
        //rot
        up.rotate_this(forward, dir.roll);
        left.rotate_this(forward, dir.roll);
    }

    void move(Vector r) {
        position = r;
    }

    [[nodiscard]] Line getLine(float x, float y) const {
        return {position, forward + step * x * left + step * y * up};
    }

private:
    float step;
    Vector position;
    Vector forward{};
    Vector up{};
    Vector left{};
};


#endif //RAYTRACING_CAMERA_H
