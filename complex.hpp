
// Complex.hpp

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <math.h>
#include <iostream>

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imag << "i)";
        return os;
    }

    bool operator==(Complex other) {
        return this->imag==other.imag&&this->real==other.real;
    }

    double magnitude() const {
        return sqrt((real*real)+(imag*imag));
    }

    // Greater than operator
    bool operator>(const Complex& other) const {
        return this->magnitude() > other.magnitude();
    }

    // Less than operator
    bool operator<(const Complex& other) const {
        return this->magnitude() < other.magnitude();
    }

    // Greater than or equal to operator
    bool operator>=(const Complex& other) const {
        return this->magnitude() >= other.magnitude();
    }

    // Less than or equal to operator
    bool operator<=(const Complex& other) const {
        return this->magnitude() <= other.magnitude();
    }

    // Equal to operator
    bool operator==(const Complex& other) const {
        return this->magnitude() == other.magnitude();
    }

    // Not equal to operator
    bool operator!=(const Complex& other) const {
        return this->magnitude() != other.magnitude();
    }
};

#endif // COMPLEX_HPP
