#include "./catch/catch.hpp"

#include "../sphere/sphere.h"
#include "../vector/vector.h"

TEST_CASE( "Sphere.isHitBy() appropriately calculates if vector travels through plane", "[Sphere]" ) {
    // define a simple ray
    const Tuple origin = Tuple(0, 0, 0);
    const Vector dir = Vector(0, 0, 1).norm();


    const double radius = 1.0;
    // define a sphere that will be hit
    const Tuple sphereWillBeHitCenter(0, 0, 2);
    const Sphere sphereWillBeHit(sphereWillBeHitCenter, radius);
    //const Tuple pointOnPlaneWillBeHit = Tuple(1, 1, 1);
    //const Vector normal = Vector(1, 1, 1).norm();
    //const Plane pWillBeHit = Plane(pointOnPlaneWillBeHit, normal);

    // define a sphere that won't be hit
    const Tuple sphereWillNotBeHitCenter(0, 0 , -2);
    const Sphere sphereWillNotBeHit(sphereWillNotBeHitCenter, radius);
    //const Tuple pointOnPlaneWillNotBeHit = Tuple(-1, -1, -1);
    //const Plane pWillNotBeHit = Plane(pointOnPlaneWillNotBeHit, normal);

    double hitExpectGtZero, \
           hitExpectLteZero;

    const Shape * const hitShape = sphereWillBeHit.isHitBy(origin, dir, hitExpectGtZero);
    const Shape * const notHitShape = sphereWillNotBeHit.isHitBy(origin, dir, hitExpectLteZero);

    
    REQUIRE ( hitShape == &sphereWillBeHit );
    REQUIRE ( hitExpectGtZero > 0.0 );

    REQUIRE ( hitExpectLteZero <= 0.0 );
    REQUIRE ( notHitShape == nullptr );
}