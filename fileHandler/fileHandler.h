#ifndef __FILE_HANDLER_H__
#define __FILE_HANDLER_H__

#include <string>
#include <memory>
#include <vector>

#include "../globals/globals.h"
#include "../world/world.h"
#include "../plane/plane.h"
#include "../sphere/sphere.h"
#include "../camera/camera.h"

namespace FileHandler {
    bool writeColorArrayToPPM(const Pixel *const colorArray,
                              const unsigned int columnCount,
                              const unsigned int rowCount,
                              const std::string &fileName);

    bool loadWorldFromFileIntoObjects(const std::string &fileName, World &world, Camera &camera);

    std::vector<std::string> tokenizeString(const std::string &string);

    std::shared_ptr<Shape const> parsePlaneFromStream(std::ifstream& stream);

    std::shared_ptr<Shape const> parseSphereFromStream(std::ifstream& stream);

    Camera parseCameraFromStream(std::ifstream& stream);
};
#endif