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
    std::shared_ptr<World> world = FileHandler::loadWorldFromFile("world.txt");

    Camera camera;

    const unsigned int width = 600;
    const unsigned int height = 400;
    const std::string fileName = "img.ppm";
    const auto pixels = camera.captureWorld((*world),
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