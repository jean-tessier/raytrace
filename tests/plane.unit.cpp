#include "./catch/catch.hpp"

#include "../plane/plane.h"
#include "../tuple/tuple.h"
#include "../vector/vector.h"

TEST_CASE( "Plane.isHitBy() appropriate calculates if vector travels through plane", "[Plane]" ) {
    // define a simple ray
    const Tuple origin = Tuple(0, 0, 0);
    const Vector dir = Vector(1, 1, 1).norm();

    // define a plane that will be hit
    const Tuple pointOnPlaneWillBeHit = Tuple(1, 1, 1);
    const Vector normal = Vector(1, 1, 1).norm();
    const Plane pWillBeHit = Plane(pointOnPlaneWillBeHit, normal);

    // define a plane that won't be hit
    const Tuple pointOnPlaneWillNotBeHit = Tuple(-1, -1, -1);
    const Plane pWillNotBeHit = Plane(pointOnPlaneWillNotBeHit, normal);

    const bool hitExpectTrue = pWillBeHit.isHitBy(origin, dir);
    const bool hitExpectFalse = pWillNotBeHit.isHitBy(origin, dir);

    REQUIRE ( hitExpectTrue == true );
    REQUIRE ( hitExpectFalse == false );
}