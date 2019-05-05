#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <string>
#include "../tuple/tuple.h"
#include "../vector/vector.h"

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
        Camera(const Camera& rhs): position{rhs.position} {}
        ~Camera() {}
        bool captureImage(const std::string& fileName);
};

#endif /* __CAMERA_H__ */