#include "plane.h"

#include <stdio.h>
#include <cmath>

/* t = ( (p_0 - l_0) dot n ) / ( l dot n )
    where t is a scalar on the normalized direction vector adjusting for distance to collision
    where p_0 is point on plane
    where l_0 is origin of ray
    where n is the normal of the plane
    where l is the direction of the ray */
const Shape * const Plane::isHitBy(const Tuple &origin, const Vector &dir, double &distance) const {
    // assume all vectors are normalized
    const double denom = dir.dot(normal);

    const Tuple normalAsTuple = Tuple(normal[0], normal[1], normal[2]);

    // avoid divide by zero
    if (std::abs(denom) > 1e-6) {
        const Tuple pointAdjustByOrigin = pointOnPlane - origin;
        const double numerator = pointAdjustByOrigin.dot(normalAsTuple);
        const double t = numerator / denom;

        if (t > 0)
        {
            distance = t;
            return this;
        }
    }

    distance = -1;
    return nullptr;
}