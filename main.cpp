#include <iostream>
#include <memory>

#include "world/world.h"
#include "plane/plane.h"
#include "tuple/tuple.h"
#include "vector/vector.h"
#include "camera/camera.h"
#include "globals/globals.h"
#include "fileHandler/fileHandler.h"

void parseCommandLineFlags(int argc, char **argv, std::string &inputFileName, std::string &outputFileName, unsigned int &width, unsigned int &height)
{
    if (argc > 1)
    {
        inputFileName = argv[1];
        if (argc > 2)
        {
            outputFileName = argv[2];
            if (argc > 4)
            {
                std::string convertedStr;
                convertedStr = argv[3];
                width = std::stod(convertedStr);
                convertedStr = argv[4];
                height = std::stod(convertedStr);
            }
        }
    }
}

int main(int argc, char **argv)
{
    

    unsigned int width = 600;
    unsigned int height = 400;
    std::string inputFileName = "world.txt";
    std::string outputFileName = "img.ppm";

    parseCommandLineFlags(argc, argv, inputFileName, outputFileName, width, height);

    Camera camera;
    World world;
    
    try
    {
        bool didLoadCorrectly = FileHandler::loadWorldFromFileIntoObjects(inputFileName, world, camera);
        if (!didLoadCorrectly) throw std::runtime_error("Could not load world from file");

        const auto pixels = camera.captureWorld(world,
                                                width,
                                                height);


        FileHandler::writeColorArrayToPPM(pixels.data(),
                                          width,
                                          height,
                                          outputFileName);
    
        std::cout << "Image capture success! File written to " << outputFileName << std::endl;
    }
    catch(...)
    {
        std::cout << "Image capture failed..." << std::endl;
    }
}