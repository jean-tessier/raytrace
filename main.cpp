#include <iostream>
#include <memory>

#include "world/world.h"
#include "plane/plane.h"
#include "tuple/tuple.h"
#include "vector/vector.h"
#include "camera/camera.h"
#include "globals/globals.h"
#include "fileHandler/fileHandler.h"

void parseCommandLineFlags(int argc, char **argv, std::string &fileName, unsigned int &width, unsigned int &height)
{
    if (argc > 1)
    {
        fileName = argv[1];
        if (argc > 3)
        {
            std::string convertedStr;
            convertedStr = argv[2];
            width = std::stod(convertedStr);
            convertedStr = argv[3];
            height = std::stod(convertedStr);
        }
    }
}

int main(int argc, char **argv)
{
    std::shared_ptr<World> world = FileHandler::loadWorldFromFile("world.txt");

    Camera camera;

    unsigned int width = 600;
    unsigned int height = 400;
    std::string fileName = "img.ppm";

    parseCommandLineFlags(argc, argv, fileName, width, height);

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