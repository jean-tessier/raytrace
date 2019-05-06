#include "./catch/catch.hpp"

#include <iterator>

#include "../camera/camera.h"
#include "../world/world.h"
#include "../globals/globals.h"
#include "../plane/plane.h"

TEST_CASE ( "Camera.captureWorld() works", "[Camera]" ) {
    World world;
    const Tuple colorGreen{0, 255, 0};
    const Plane plane(
        {0, 0, 3},
        {0, 0, 1},
        colorGreen
    );
    world.addShape(std::make_shared<Plane>(plane));
    const Camera camera;
    const unsigned int width = 600;
    const unsigned int height = 400;

    std::vector<Pixel> resultArr = camera.captureWorld(world, width, height);

    REQUIRE( resultArr.size() == width * height );

    bool allPixelsApproximatelyCorrect = true;
    for (const auto &pixel : resultArr)
    {
        if (pixel.r > 0.0 || pixel.g <= 0.0 || pixel.b > 0.0)
        {
            allPixelsApproximatelyCorrect = false;
            break;
        }
    }

    REQUIRE( allPixelsApproximatelyCorrect == true );
}