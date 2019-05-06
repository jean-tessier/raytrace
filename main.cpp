#include <iostream>
#include <memory>

#include "world/world.h"
#include "plane/plane.h"
#include "tuple/tuple.h"
#include "vector/vector.h"
#include "camera/camera.h"

int main(int argc, char **argv)
{
    Tuple pointOnPlane{0, 0, 3};
    Vector normalA{1, 0, 1};
    Vector normalB{-1, 0, 1};
    Tuple color{0, 255, 0};

    std::shared_ptr<Shape const> planeA = std::make_shared<Plane>(pointOnPlane, normalA.norm(), color);
    std::shared_ptr<Shape const> planeB = std::make_shared<Plane>(pointOnPlane, normalB.norm(), color);

    World world;
    world.addShape(planeA);
    world.addShape(planeB);

    Camera camera;

    std::cout << "Hello world!" << std::endl;
}