#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector {
    private:
        double dim[3];

    public:
        Vector() {}
        Vector(const double& x, const double& y, const double& z) {
            dim[0] = x;
            dim[1] = y;
            dim[2] = z;
        }
        Vector(const Vector& rhs) {
            for(int i = 0; i < 3; ++i) {
                dim[i] = rhs[i];
            }
        }
        ~Vector() {};

        // operator overloads
        const double& operator[](const int& i) const { return dim[i]; }
        double& operator[](const int& i) { return dim[i]; }

        // members
        Vector add(const Vector& rhs) const;
        Vector subtract(const Vector& rhs) const;
        Vector multiply(const Vector& rhs) const;
        Vector scale(const double& scaleVal) const;
        double dot(const Vector& rhs) const;
        double len() const;
        Vector normal() const;
        Vector reflect(const Vector& reflectionVector) const;

        // friends
};

#endif __VECTOR_H__