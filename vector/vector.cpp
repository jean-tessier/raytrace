#include <cmath>

#include "vector.h"

Vector Vector::add(const Vector& rhs) const {
    return Vector( dim[0]+rhs[0], dim[1]+rhs[1], dim[2]+rhs[2] );
}

Vector Vector::subtract(const Vector& rhs) const {
    return Vector( dim[0]-rhs[0], dim[1]-rhs[1], dim[2]-rhs[2] );
}

Vector Vector::multiply(const Vector& rhs) const {
    return Vector( dim[0]*rhs[0], dim[1]*rhs[1], dim[2]*rhs[2] );
}

Vector Vector::scale(const double& scaleVal) const {
    return Vector( dim[0] * scaleVal, dim[1] * scaleVal, dim[2] * scaleVal );
}

double Vector::dot(const Vector& rhs) const {
    return dim[0]*rhs[0] + dim[1]*rhs[1] + dim[2]*rhs[2];
}

double Vector::len() const {
    return std::sqrt(dim[0]*dim[0] + dim[1]*dim[1] + dim[2]*dim[2]);
}

Vector Vector::norm() const {
    const double length = this->len();

    return Vector(dim[0]/length, dim[1]/length, dim[2]/length);
}

// r = d - 2(d dot n)n
// n must be normalized, is the normal of the surface being reflected across
// d is 'this'
Vector Vector::reflect(const Vector& reflectionVector) const {
    Vector sourceVector(*this);
    // TODO: implement operator overloading for this to work
    Vector reflectedVector = sourceVector - 2 * (sourceVector.dot(reflectionVector)) * reflectionVector;
    return reflectedVector;
}