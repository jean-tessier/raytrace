#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <memory>

#include "../tuple/tuple.h"
#include "../vector/vector.h"

class Shape {
    private:
    protected:
        Tuple color;
    public:
        Shape(): color() {}
        Shape(const Tuple& c): color(c) {}
        Shape(const Shape& rhs): color(rhs.color) {}
        ~Shape() {}

        Tuple getColor() const { return color; }
        virtual const Shape * const isHitBy(const Tuple& origin, const Vector& dir, double &distance) const = 0;
};

#endif /* __SHAPE_H__ */