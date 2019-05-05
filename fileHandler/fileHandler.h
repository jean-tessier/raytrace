#ifndef __FILE_HANDLER_H__
#define __FILE_HANDLER_H__

#include <string>

namespace FileHandler {
    typedef struct pixelType {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    } Pixel;

    // input: reference to array of pixels
    bool writeColorArrayToPPM(const Pixel *const colorArray,
                              const unsigned int columnCount,
                              const unsigned int rowCount,
                              const std::string &fileName);
};

#endif