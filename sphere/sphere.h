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
        ~Sphere() {}

        virtual const Shape * const isHitBy(const Tuple &origin, const Vector &dir, double &distance) const;

        Tuple GetCenter() const { return center; }
        double GetRadius() const { return radius; }
};

#endif /* __SPHERE_H__ */