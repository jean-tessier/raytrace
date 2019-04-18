#include "camera.h"

#include <stdio.h>

#include "../plane/plane.h"

bool Camera::captureImage(const std::string& fileName) {
    FILE* pFile;

    int cols = 600;
    int rows = 400;
    int brightness = 255;
    int pixelCount = cols * rows;
    Pixel arr[pixelCount];
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
            std::cout << "x: " << viewportX << ", y: " << viewportY << ", z: " << viewportZ << std::endl;

            double t = testPlane.isHitBy(position, viewVector.norm());
            std::cout << "t = " << t << std::endl;

            if (t > 0)
            {
                std::cout << "HIT" << std::endl;
                Tuple color = testPlane.getColor();
                arr[y * cols + x] = {(unsigned char)(color[0] / t), (unsigned char)(color[1] / t), (unsigned char)(color[2] / t)};
            }
            else
            {
                std::cout << "MISS" << std::endl;
                arr[y * cols + x] = (Pixel) {255, 0, 0};
            }
        }
    }

    pFile = fopen(fileName.c_str(), "w");
    fprintf(pFile, "P6 %d %d %d\n", cols, rows, brightness);
    fwrite(arr, sizeof(Pixel), sizeof(arr), pFile);
    fclose(pFile);
    
    return true;
}