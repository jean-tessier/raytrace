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
    double distance;
    double recentDistance;
    const Shape *hitShape;
    const Shape *recentShape;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            distance = -1;
            recentDistance = -1;
            hitShape = nullptr;
            recentShape = nullptr;            
            double viewportX = viewportXIncrementer * x + viewportXCoordMin;
            double viewportY = viewportYIncrementer * y + viewportYCoordMin;
            Vector viewVector{viewportX, viewportY, viewportZ};

            for (const auto &shape : shapes) {
                recentShape = shape->isHitBy(position, viewVector.norm(), recentDistance);
                // see if the recently hit shape is closer than the previously closest shape
                if (distance < 0 || (recentDistance > 0 && recentDistance < distance))
                {
                    hitShape = recentShape;
                    distance = recentDistance;
                }
            }

            if (distance > 0)
            {
                const Tuple color = hitShape->getColor();
                imagePixels.push_back({(unsigned char)(color[0] / distance), (unsigned char)(color[1] / distance), (unsigned char)(color[2] / distance)});
            }
            else
            {
                imagePixels.push_back({0, 0, 0});
            }
        }
    }
        
    return imagePixels;
}
