#include "camera.h"

#include <stdio.h>

#include "../plane/plane.h"

std::vector<Pixel> Camera::captureWorld(const World& world,
                                        const unsigned int width,
                                        const unsigned int height) const
{
    double viewportXCoordMin = viewportBounds[0][0]; // bottom-left, x
    double viewportXCoordMax = viewportBounds[1][0]; // top-right, x
    double viewportXIncrementer = (viewportXCoordMax - viewportXCoordMin) / width;

    double viewportYCoordMin = viewportBounds[0][1];
    double viewportYCoordMax = viewportBounds[1][1];
    double viewportYIncrementer = (viewportYCoordMax - viewportYCoordMin) / height;

    // it seems counter intuitive to do rows on the outside, but we need to fill each column of a single row first
    double viewportZ = viewportBounds[0][2];

    std::list<std::shared_ptr<Shape const>> shapes = world.getShapes();

    std::vector<Pixel> imagePixels;
    double t;
    const Shape *hitShape;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            t = -1;
            
            double viewportX = viewportXIncrementer * x + viewportXCoordMin;
            double viewportY = viewportYIncrementer * y + viewportYCoordMin;
            Vector viewVector{viewportX, viewportY, viewportZ};

            for (const auto &shape : shapes) {
                hitShape = shape->isHitBy(position, viewVector.norm(), t);
                if (t > 0) break;
            }

            if (t > 0)
            {
                Tuple color = {0, 255, 0};// shape.getColor();
                imagePixels.push_back({(unsigned char)(color[0] / t), (unsigned char)(color[1] / t), (unsigned char)(color[2] / t)});
            }
            else
            {
                imagePixels.push_back({0, 0, 0});
            }
        }
    }
        
    return imagePixels;
}
