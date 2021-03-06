#include <stdio.h>
#include <fstream>
#include <sstream>

#include "fileHandler.h"

std::string &trimInPlace(std::string &str)
{
    if(str == "") return str;
    const size_t first = str.find_first_not_of(' ');
    const size_t last = str.find_last_not_of(' ');
    str = str.substr(first, (last-first+1));

    return str;
}

bool FileHandler::writeColorArrayToPPM(const Pixel *const colorArray,
                                       const unsigned int columnCount,
                                       const unsigned int rowCount,
                                       const std::string &fileName)
{
    // open the destination file for reading
    FILE *destinationFile;
    destinationFile = fopen(fileName.c_str(), "w");

    // write the ppm header
    // P6 designates file as ppm, then define columns, rows, and max brightness
    fprintf(destinationFile,
            "P6 %d %d %d\n",
            columnCount,
            rowCount,
            255);
    // write the data in bulk to the destination file
    fwrite(colorArray,
           sizeof(Pixel),
           sizeof(Pixel) * columnCount * rowCount,
           destinationFile);

    // clean up
    fclose(destinationFile);

    return true;
}

bool FileHandler::loadWorldFromFileIntoObjects(const std::string &fileName, World &world, Camera &camera)
{
    bool didParseWorld = false;
    bool didParseCamera = false;

    world = World();
    camera = Camera();

    try
    {
        std::ifstream inputStream(fileName);

        std::string line;
        std::vector<std::string> tokens;
        std::shared_ptr<Shape const> shape;
        while (std::getline(inputStream, line))
        {
            trimInPlace(line);
            if (line == "camera")
            {
                camera = FileHandler::parseCameraFromStream(inputStream);
                didParseCamera = true;
            }
            else if(line == "plane")
            {
                shape = FileHandler::parsePlaneFromStream(inputStream);
                world.addShape(shape);
            }
            else if(line == "sphere")
            {
                shape = FileHandler::parseSphereFromStream(inputStream);
                world.addShape(shape);
            }
        }
        inputStream.close();
        didParseWorld = true;
    }
    // catch whatever ifstream() throws
    catch(...)
    {
        // probably write a message about the exception here...
        return false;
    }

    return didParseWorld && didParseCamera;
}

std::vector<std::string> FileHandler::tokenizeString(const std::string &string)
{
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream stream(string);

    while (std::getline(stream, token, ' '))
    {
        if (token != "")
        {
            tokens.push_back(token);
        }
    }

    return tokens;
}

std::shared_ptr<Shape const> FileHandler::parsePlaneFromStream(std::ifstream& stream)
{
    Tuple pointOnPlane;
    Vector normal;
    Tuple color;

    std::string line;
    std::vector<std::string> tokens;
    std::getline(stream, line); // skip opening {
    while (std::getline(stream, line) && trimInPlace(line) != "}")
    {
        tokens = FileHandler::tokenizeString(line);
        if (tokens[0] == "point")
        {
            pointOnPlane = {std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
        }
        else if (tokens[0] == "normal")
        {
            normal = {std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
        }
        else if (tokens[0] == "color")
        {
            color = {std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
        }
    }

    return std::make_shared<Plane>(pointOnPlane, normal, color);
}

std::shared_ptr<Shape const> FileHandler::parseSphereFromStream(std::ifstream& stream)
{
    Tuple center;
    double radius;
    Tuple color;

    std::string line;
    std::vector<std::string> tokens;
    std::getline(stream, line); // skip opening {
    while (std::getline(stream, line) && trimInPlace(line) != "}")
    {
        tokens = FileHandler::tokenizeString(line);
        if (tokens[0] == "center")
        {
            center = {std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
        }
        else if (tokens[0] == "radius")
        {
            radius = std::stod(tokens[1]);
        }
        else if (tokens[0] == "color")
        {
            color = {std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
        }
    }

    return std::make_shared<Sphere>(center, radius, color);
}

Camera FileHandler::parseCameraFromStream(std::ifstream& stream)
{
    Tuple position;
    Tuple viewportBounds[2]{
        {-1, -1, 1},
        {1, 1, 1}
    };

    std::string line;
    std::vector<std::string> tokens;
    std::getline(stream, line); // skip opening {
    while (std::getline(stream, line) && trimInPlace(line) != "}")
    {
        tokens = FileHandler::tokenizeString(line);
        if (tokens[0] == "position")
        {
            position = Tuple{std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
        }
        else if (tokens[0] == "viewBounds")
        {
            std::getline(stream, line); // skip opening {
            while (std::getline(stream, line) && trimInPlace(line) != "}")
            {
                tokens = FileHandler::tokenizeString(line);
                if (tokens[0] == "lowerLeft")
                {
                    viewportBounds[0] = Tuple{std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
                }
                else if (tokens[0] == "upperRight")
                {
                    viewportBounds[1] = Tuple{std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3])};
                }
            }
        }
    }

    return Camera(position, viewportBounds);
}
