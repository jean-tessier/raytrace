#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "world/world.h"
#include "plane/plane.h"
#include "tuple/tuple.h"
#include "vector/vector.h"
#include "camera/camera.h"

#include "globals/globals.h"
#include "fileHandler/fileHandler.h"

std::vector<std::string> stringifyArgv(int argc, char **argv)
{
    std::vector<std::string> vectorOfStringifiedArgvs;
    std::string value;
    for(int i = 0; i < argc; ++i)
    {
        value = argv[i];
        vectorOfStringifiedArgvs.push_back(value);
    }

    return vectorOfStringifiedArgvs;
}

void parseCommandLineFlags(int argc, char **argv, std::string &inputFileName, std::string &outputFileName, unsigned int &width, unsigned int &height)
{
    std::vector<std::string> argvs = stringifyArgv(argc, argv);

    if(argvs.size() > 1)
    {
        auto inputFlagIterator = std::find(argvs.begin(), argvs.end(), "-i");
        if(inputFlagIterator != argvs.end() && ++inputFlagIterator != argvs.end())
        {
            inputFileName = (*inputFlagIterator);
        }
        auto outputFlagIterator = std::find(argvs.begin(), argvs.end(), "-o");
        if(outputFlagIterator != argvs.end() && ++outputFlagIterator != argvs.end())
        {
            outputFileName = (*outputFlagIterator);
        }
        auto widthFlagIterator = std::find(argvs.begin(), argvs.end(), "-w");
        if(widthFlagIterator != argvs.end() && ++widthFlagIterator != argvs.end())
        {
            width = std::stod((*widthFlagIterator));
        }
        auto heightFlagIterator = std::find(argvs.begin(), argvs.end(), "-h");
        if(heightFlagIterator != argvs.end() && ++heightFlagIterator != argvs.end())
        {
            height = std::stod((*heightFlagIterator));
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