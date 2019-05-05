#include <stdio.h>

#include "fileHandler.h"

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