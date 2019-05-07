#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "../tuple/tuple.h"

class Vector {
    private:
        // double dim[3];
        Tuple dim;

    public:
        Vector() {}
        Vector(const double& x, const double& y, const double& z): dim(x, y, z) {}
        Vector(const Tuple &rhs): dim(rhs) {}
        Vector(const Vector& rhs): dim(rhs.dim) {}
        ~Vector() {};

        // operator overloads
        const double& operator[](const int& i) const { return dim[i]; }
        double& operator[](const int& i) { return dim[i]; }
        Vector operator-(const Vector& rhs) const { return this->subtract(rhs); }
        Vector operator*(const Vector& rhs) const { return this->multiply(rhs); }
        bool operator==(const Vector& rhs) const { return dim == rhs.dim; }


        // members
        Vector add(const Vector& rhs) const;
        Vector subtract(const Vector& rhs) const;
        Vector multiply(const Vector& rhs) const;
        Vector scale(const double& scaleVal) const;
        double dot(const Vector& rhs) const;

        double len() const;
        Vector norm() const;
        Vector reflect(const Vector& reflectionVector) const;

        // friends
        friend Vector operator*(const Vector& lhs, const double& rhs) { return lhs.scale(rhs); }
        friend Vector operator*(const double& lhs, const Vector& rhs) { return rhs.scale(lhs); }
};

#endif /* __VECTOR_H__ */