#ifndef __TUPLE_H__
#define __TUPLE_H__

#include <iostream>

class Tuple {
    private:
        double values[3];
    public:
        Tuple() {
            for(int i=0; i<3; ++i) {
                values[i] = 0;
            }
        }
        Tuple(const double& x, const double& y, const double& z) {
            values[0] = x;
            values[1] = y;
            values[2] = z;
        }
        Tuple(const Tuple& rhs) {
            for(int i=0; i<3; ++i) {
                values[i] = rhs.values[i];
            }
        }
        ~Tuple() {}

        Tuple add(const Tuple& rhs) const;
        Tuple subtract(const Tuple& rhs) const;
        Tuple multiply(const Tuple& rhs) const;
        Tuple scale(const double& rhs) const;
        double dot(const Tuple& rhs) const;

        // operator overloads
        const double& operator[](const int& i) const { return values[i]; }
        double& operator[](const int& i) { return values[i]; }
        Tuple operator+(const Tuple& rhs) const { return this->add(rhs); }
        Tuple operator-(const Tuple& rhs) const { return this->subtract(rhs); }
        bool operator==(const Tuple& rhs) const { return (values[0] == rhs.values[0] && values[1] == rhs.values[1] && values[2] == rhs.values[2]); }

        // friends
        friend std::ostream& operator<<(std::ostream& lhs, const Tuple& rhs) { return lhs << rhs.values[0] << " " << rhs.values[1] << " " << rhs.values[2]; }
};

#endif /* __TUPLE_H__ */