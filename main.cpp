
#include "render/Scene.h"
#include "render/Renderer.h"
#include "math/Solids.h"

Scene getScene() {

    return Scene({
                     (new Sphere({4.5, 0, 1}, 0.5))
                         ->setTexture(new SolidColor(BLUE)),
                     (new Sphere({5, 2, 0}, 1.5, {0, -90_o, 0}))
                         ->setTexture((new Squares(RED, YELLOW))->addTransform(fromSpherical()))
                         ->setBound([](Point p) { return p.y < std::sin(p.x * 10) / 2; }),
                     (new Sphere({4, -1, -2}, 1))
                         ->setTexture(new Gradient("0000FF", "000000", -1, 1)),
                     (new Sphere({2, 2, 0}, 1))
                         ->setMaterial(new Refractive(1, 1.5)),
                     (new Sphere({6, -3, -1}, 2))
                         ->setMaterial(new Mirror()),
                     (new Sphere({5, -2, 1}, 1, {135_o, -45_o, 22.5_o}))
                         ->setTexture((new Squares(WHITE, RED, 2))->addTransform(fromSpherical())),
                     (new Plane({1, 0, 0}, {0, 1, 0}, {0, 0, -4}))
                         ->setTexture(new Squares(WHITE, BLACK))
                         ->setBound([](Point p) { return p.x < 15; }),
                     (new Plane({1, 0, 0}, {0, 1, 0}, {0, 0, -3}))
                         ->setTexture(new Squares(GREEN, BLACK))
                         ->setBound(circle({3, 3}, 2)),
                     (new Plane({0, 0, 1}, {0, 1, 0}, {3, 0, 0}))
                         ->setTexture(new SolidColor("FFE098"))
                         ->setBound(circle({0, 0}, 1))
                         ->setMaterial(new Translucent(0.5)),
                     (new Cylinder({-3, -1, -6}, {22.5_o, 22.5_o, 22.5_o}, 1))
                         ->setTexture((new Squares(GREEN, BLUE))->addTransform(fromCylindrical()))
                         ->setBound(lengthConstrain(7, 13))
                 },
                 Camera({-4, 0, 3},
                        {0, 30_o, 0},
                        {500, 500}, 1)
    );
}

Scene getShape() {

    return Scene({
                     // Flower
                     (new Sphere({0, 0, 0}, 1.5, {0, -90_o, 10_o}))
                         ->setTexture((new Gradient(RED, YELLOW, -90_o, 75_o))->addTransform(fromSpherical()))
                         ->setBound([](Point p) { return p.y < std::sin(p.x * 10) / 2; }),
                     (new Sphere({0, 0, -1}, 0.5))
                         ->setTexture(new Gradient("AD0000", RED, -90_o, 90_o)),
                     // Pads
                     (new Plane({1, 0, 0}, {0, 1, 0}, {-.3, .3, -1.6}))
                         ->setTexture((new Gradient("49CE00", "01A600", 0, 2))
                         ->addTransform([](Point p) { return Point(0,std::sqrt(sqr(p.x + 0.3)+ sqr(p.y - .3)));
                                          }))
                         ->setBound(circle(2)), (new Plane({1, 0, 0}, {0, 1, 0}, {0, -.6, -1.5}))
                         ->setTexture((new Gradient("49CE00", "14BF13", 0, 1.5))
                                          ->addTransform([](Point p) { return Point(0,
                                                                                    std::sqrt(
                                                                                        sqr(p.x) + sqr(p.y + .6)));
                                          }))
                         ->setBound(circle(1.5))
                 },
                 Camera({-6, 0, 3},
                        {0, 35_o, 0},
                        {500, 500}, 1)
    );
}

Scene getDick() {
    return Scene({
                     // Body
                     (new Cylinder({5, 3, 0}, {-90_o, 0, 0}, 0.75))
                         ->setTexture(new Gradient("F5F5DC", "D6B187", 0, 90_o))
                         ->setBound([](Point p) { return p.x > 0 && p.x < 6; }),
                     // Balls
                     (new Sphere({6, 3, .1}, 1.1))
                         ->setTexture(new Gradient("D6B187", "F5F5DC", 0, 90_o)),
                     (new Sphere({4, 3, .1}, 1.1))
                         ->setTexture(new Gradient("D6B187", "F5F5DC", 0, 90_o)),
                     // Head
                     (new Sphere({5, -3, 0}, 0.8))
                         ->setTexture(new Gradient("CC00CC", "FF00FF", 0, 90_o))
                         ->setBound([](Point p) {
                             return !(p.x > -110_o && p.x < -70_o && p.y < 60_o && p.y > -60_o);
                         }),
                     (new Sphere({5, -3, 0}, 0.7))
                         ->setTexture(new SolidColor(BLACK))
                 }, Camera({0, -5, 4},
                           {45_o, 30_o, 0},
                           {500, 500}, 1));
}

Scene getMirror() {
    float mirror_size = 5;
    float backdrop_size = 5;
    return Scene({
                     (new Sphere({0, 0, 0}, 1, {135_o, -60_o, 30_o}))
                         ->setTexture((new Squares(BLUE, GREEN))->addTransform(fromSpherical())),
                     // Mirror 1
                     (new Plane({5, -1, 0}, {0, 0, 1}, {1, 2, 0}))
                         ->setMaterial(new Mirror(0.2))
                         ->setTexture(new SolidColor("009A51"))
                         ->setBound(square(mirror_size)),
                     // Mirror 2
                     (new Plane({-5, -1, 0}, {0, 0, 1}, {1, -2, 0}))
                         ->setMaterial(new Mirror(0.2))
                         ->setTexture(new SolidColor("009A51"))
                         ->setBound(square(mirror_size)),
                     // Backdrop
                     (new Plane({0, 0, 1}, {0, 1, 0}, {10, 0, 0}))
                         ->setTexture(new Squares(BLACK, WHITE))
                         ->setBound(square(backdrop_size))

                 }, Camera({-10, 0, 3},
                           {0, 15_o, 0},
                           {500, 500}, 1));
}

int main() {
    std::string output_dir = "/home/ilyabelow/Code/raytracing/output/";
    std::string file_ext = ".bmp";

    Scene scene = getShape();

    Renderer renderer(&scene);
    renderer.render(output_dir + "shape" + file_ext);

    return 0;
}
