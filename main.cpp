#include <iostream>
#include <memory>

#include "world/world.h"
#include "plane/plane.h"
#include "tuple/tuple.h"
#include "vector/vector.h"
#include "camera/camera.h"
#include "globals/globals.h"
#include "fileHandler/fileHandler.h"

int main(int argc, char **argv)
{
    Tuple pointOnPlane{0, 0, 3};
    Vector normalA{1, 0, 1};
    Vector normalB{-1, 0, 1};
    Tuple color{0, 0, 255};

    std::shared_ptr<Shape const> planeA = std::make_shared<Plane>(pointOnPlane, normalA.norm(), color);
    std::shared_ptr<Shape const> planeB = std::make_shared<Plane>(pointOnPlane, normalB.norm(), color);

    World world;
    world.addShape(planeA);
    world.addShape(planeB);

    Camera camera;

    const unsigned int width = 600;
    const unsigned int height = 400;
    const std::string fileName = "img.ppm";
    const auto pixels = camera.captureWorld(world,
                                            width,
                                            height);

    try
    {
        FileHandler::writeColorArrayToPPM(pixels.data(),
                                          width,
                                          height,
                                          fileName);
    
        std::cout << "Image capture success! File written to " << fileName << std::endl;
    }
    catch(...)
    {
        std::cout << "Image capture failed..." << std::endl;
    }
}