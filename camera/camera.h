#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <string>
#include <vector>
#include "../tuple/tuple.h"
#include "../vector/vector.h"
#include "../world/world.h"
#include "../globals/globals.h"

class Camera {
    private:
        Tuple position;
        Tuple viewportBounds[2]; // bot-left, top-right
    public:
        Camera(): position{0, 0, 0},
                  viewportBounds{
                      {-1, -1, 1},
                      {1, 1, 1}
                  }
        {}
        Camera(const double width, const double height):
            position{0, 0, 0}
        {
            const double widthPerHeight = width / height;
            viewportBounds[0] = {-widthPerHeight, 1.0/(-widthPerHeight), 1};
            viewportBounds[1] = {widthPerHeight, 1.0/(widthPerHeight), 1};
        }
        Camera(const Tuple &position, const Tuple viewportBounds[2]) :
            position(position),
            viewportBounds{viewportBounds[0], viewportBounds[1]}
        {}
        Camera(const Camera& rhs): position{rhs.position} {}
        ~Camera() {}

        Tuple GetPosition() const { return position; }
        const Tuple *const GetViewportBounds() const { return viewportBounds; }

        std::vector<Pixel> captureWorld(const World& world,
                           const unsigned int width,
                           const unsigned int height) const;
};

#endif /* __CAMERA_H__ */