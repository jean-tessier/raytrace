#include "sphere.h"

#include <cmath>

const Shape * const Sphere::isHitBy(const Tuple &origin, const Vector &dir, double &distance) const
{
    distance = -1.0;

    // A = origin
    // B = unit vector, direction
    // C = sphere center point
    // r = sphere radius

    // at^2 + bt + c = 0 -> t = (-b +/- sqrt(b^2 - 4ac)) / (2a)
    // where t is distance to collision
    Vector rayOriginMinusSphereCenter = origin - center;
    const double a = dir.dot(dir);
    const double b = 2 * dir.dot(rayOriginMinusSphereCenter);
    const double c = rayOriginMinusSphereCenter.dot(rayOriginMinusSphereCenter) - (radius * radius);
    const double discriminant = (b*b) - (4*a*c);

    if (discriminant > 0) // line does not intersect
    {
        double t = ((-b) - std::sqrt(discriminant)) / (2 * a);
        if (t > 0)
        {
            distance = t;
            return this;
        }
    }

    return nullptr;
}