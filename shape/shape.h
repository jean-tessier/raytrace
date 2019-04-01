#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "../tuple/tuple.h"
#include "../vector/vector.h"

class Shape {
    private:
    public:
        virtual bool isHitBy(const Tuple& origin, const Vector& dir) const = 0;
};

#endif /* __SHAPE_H__ */