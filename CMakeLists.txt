cmake_minimum_required(VERSION 3.19)
project(raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(raytracing main.cpp render/ImageSaver.cpp render/ImageSaver.h color/Color.h math/primitives/Vector.h math/primitives/Line.h math/solids/Sphere.h render/Scene.h math/solids/Solid.h math/primitives/Vector.cpp render/Camera.h math/solids/Plane.h color/Texture.h color/Texture.cpp math/primitives/Direction.h math/Solids.h render/Renderer.h color/Color.cpp math/Support.h math/primitives/Point.h render/Renderer.cpp color/Material.cpp color/Material.h math/Bonds.h math/Bonds.cpp math/Transforms.cpp math/Transforms.h math/Support.cpp math/solids/Cylinder.h render/Pixel.h)
