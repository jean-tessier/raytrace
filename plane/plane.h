#ifndef __PLANE_H__
#define __PLANE_H__

#include "../shape/shape.h"
#include "../tuple/tuple.h"
#include "../vector/vector.h"

class Plane: public Shape {
    private:
        Tuple pointOnPlane;
        Vector normal;
    public:
        Plane(): pointOnPlane(), normal(), Shape() {}
        Plane(const Tuple& p, const Vector& n): pointOnPlane(p), normal(n), Shape() {}
        Plane(const Tuple& p, const Vector& n, const Tuple& c): pointOnPlane(p), normal(n), Shape(c) {}
        Plane(const Plane& rhs): pointOnPlane(rhs.pointOnPlane), normal(rhs.normal), Shape(rhs) {} // copy shape here
        ~Plane() {}

        virtual const Shape * const isHitBy(const Tuple &origin, const Vector &dir, double &distance) const;

        Tuple GetPointOnPlane() const { return pointOnPlane; }
        Vector GetNormal() const { return normal; }
};

#endif /* __PLANE_H__ */