#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "../shape/shape.h"
#include "../tuple/tuple.h"
#include "../vector/vector.h"

class Sphere: public Shape {
    private:
        const Tuple center;
        const double radius;
    public:
        Sphere() :
            Shape(),
            center(0, 0, 0),
            radius(1)
        {}
        Sphere(const Tuple &center, const double radius) :
            Shape(),
            center(center),
            radius(radius)
        {}
        Sphere(const Tuple &center, const double radius, const Tuple &color) :
            Shape(color),
            center(center),
            radius(radius)
        {}
        /*Plane(const Tuple& p, const Vector& n): pointOnPlane(p), normal(n), Shape() {}
        Plane(const Tuple& p, const Vector& n, const Tuple& c): pointOnPlane(p), normal(n), Shape(c) {}
        Plane(const Plane& rhs): pointOnPlane(rhs.pointOnPlane), normal(rhs.normal), Shape(rhs) {} // copy shape here*/
        ~Sphere() {}

        virtual const Shape * const isHitBy(const Tuple &origin, const Vector &dir, double &distance) const;
};

#endif /* __SPHERE_H__ */