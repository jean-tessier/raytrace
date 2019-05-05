#include "camera.h"

#include <stdio.h>

#include "../plane/plane.h"
#include "../fileHandler/fileHandler.h"

bool Camera::captureImage(const std::string& fileName) {
    int cols = 600;
    int rows = 400;
    FileHandler::Pixel arr[cols * rows];

    Tuple pointOnPlane{0, 0, 3};
    Vector normal{0, 0, 1};
    Tuple color{0, 255, 0};
    Plane testPlane(pointOnPlane, normal.norm(), color);

    double viewportXCoordMin = viewportBounds[0][0]; // bottom-left, x
    double viewportXCoordMax = viewportBounds[1][0]; // top-right, x
    double viewportXIncrementer = (viewportXCoordMax - viewportXCoordMin) / cols;

    double viewportYCoordMin = viewportBounds[0][1];
    double viewportYCoordMax = viewportBounds[1][1];
    double viewportYIncrementer = (viewportYCoordMax - viewportYCoordMin) / rows;

    // it seems counter intuitive to do rows on the outside, but we need to fill each column of a single row first
    double viewportZ = viewportBounds[0][2];
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            double viewportX = viewportXIncrementer * x + viewportXCoordMin;
            double viewportY = viewportYIncrementer * y + viewportYCoordMin;
            Vector viewVector{viewportX, viewportY, viewportZ};

            double t = testPlane.isHitBy(position, viewVector.norm());

            if (t > 0)
            {
                Tuple color = testPlane.getColor();
                arr[y * cols + x] = {(unsigned char)(color[0] / t), (unsigned char)(color[1] / t), (unsigned char)(color[2] / t)};
            }
            else
            {
                arr[y * cols + x] = (FileHandler::Pixel) {255, 0, 0};
            }
        }
    }

    return FileHandler::writeColorArrayToPPM(arr, cols, rows, fileName);
}