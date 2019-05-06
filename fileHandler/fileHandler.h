#ifndef __FILE_HANDLER_H__
#define __FILE_HANDLER_H__

#include <string>

#include "../globals/globals.h"

namespace FileHandler {
    // input: reference to array of pixels
    bool writeColorArrayToPPM(const Pixel *const colorArray,
                              const unsigned int columnCount,
                              const unsigned int rowCount,
                              const std::string &fileName);
};

#endif