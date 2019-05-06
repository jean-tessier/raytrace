#include "./catch/catch.hpp"

#include <iterator>

#include "../camera/camera.h"
#include "../world/world.h"
#include "../globals/globals.h"

TEST_CASE ( "Camera.captureWorld() works", "[Camera]" ) {
    const World world;
    const Camera camera;
    const unsigned int width = 600;
    const unsigned int height = 400;

    std::vector<Pixel> resultArr = camera.captureWorld(world, width, height);

    REQUIRE( resultArr.size() == width * height );
}