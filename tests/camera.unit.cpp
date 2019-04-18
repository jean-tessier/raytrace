#include "./catch/catch.hpp"

#include "../camera/camera.h"

TEST_CASE ( "Camera.captureImage() works", "[Camera]" ) {
    Camera c = Camera();

    c.captureImage("img.ppm");
}