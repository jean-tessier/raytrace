#include "tuple.h"

Tuple Tuple::add(const Tuple& rhs) const {
    return Tuple(values[0] + rhs[0], values[1] + rhs[1], values[2] + rhs[2]);
}

Tuple Tuple::subtract(const Tuple& rhs) const {
    return Tuple(values[0] - rhs[0], values[1] - rhs[1], values[2] - rhs[2]);
}

Tuple Tuple::multiply(const Tuple& rhs) const {
    return Tuple(values[0] * rhs[0], values[1] * rhs[1], values[2] * rhs[2]);
}

Tuple Tuple::scale(const double& rhs) const {
    return Tuple(values[0] * rhs, values[1] * rhs, values[2] * rhs);
}

double Tuple::dot(const Tuple& rhs) const {
    return values[0]*rhs[0] + values[1]*rhs[1] + values[2]*rhs[2];
}