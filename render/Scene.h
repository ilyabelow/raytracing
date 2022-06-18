//
// Created by ilyabelow on 29.05.2022.
//

#ifndef RAYTRACING_SCENE_H
#define RAYTRACING_SCENE_H

#include <utility>
#include <vector>
#include "../math/solids/Solid.h"
#include "Camera.h"

struct Collision {
    float t;
    Solid *solid;

    [[nodiscard]] bool collided() const {
        return solid != nullptr;
    }
};

class Scene {
public:
    Camera camera;

    explicit Scene(std::vector<Solid *> &&init, Camera&& camera) : solids(std::move(init)), camera(std::move(camera)) {

    }

    ~Scene() {
        for (auto &solid : solids) {
            delete solid;
        }
    }

    [[nodiscard]] Collision intersect(const Line &line) const {
        float t = std::numeric_limits<float>::max();
        Solid *solid = nullptr;
        for (auto &cur_solid : solids) {
            auto opt_t = cur_solid->intersect(line);
            if (opt_t.has_value() && opt_t.value() < t) {
                solid = cur_solid;
                t = opt_t.value();
            }
        }
        return {t, solid};
    }

private:
    std::vector<Solid *> solids;

};

#endif //RAYTRACING_SCENE_H
