/**
 * @file    data_structures.h
 * @author  Bruno Pezer
 * @brief   C++ implementations of data structures from Alan Bertossi's "Algoritmi e strutture di dati".
 * @version 0.2
 * @date    2023-07-02
 *
 * @copyright NO Copyright !(c) 2023
 *
 */
#include <iostream>
#include <math.h>

/**
 * @brief Implementation of a class representing complex numbers.
 *
 */
class Complex {
public:
    Complex();
    Complex(double r, double i);
    double mod();
    double arg();
    double getReal();
    double getImag();
    void add(Complex c);
    void sub(Complex c);
    void mult(Complex c);
    void div(Complex c);
    Complex coniug();
    friend std::ostream& operator<<(std::ostream& out, Complex& c) {
        out << "(" << c.getReal() << ", " << c.getImag() << ")";
        return out;
    }
private:
    double real;
    double imag;
};

Complex::Complex() { real = imag = 0; }

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

// Returns the modulus of a complex number.
double Complex::mod() { return sqrt((real * real) + (imag * imag)); }

// Returns the argument of a complex number.
double Complex::arg() {
    if (real == 0 && imag == 0) {
        // TODO: find more appropriate exception.
        throw std::invalid_argument{"Complex::arg(): undefined case."};
    }
    double a;
    if (real == 0 && imag > 0) a = M_PI / 2;
    if (real == 0 && imag < 0) a = 3 * M_PI / 2;
    if (real > 0 && imag >= 0) a = atan(imag / real);
    if (real > 0 && imag < 0) a = atan(imag / real) + 2 * M_PI;
    if (real < 0) a = atan(imag / real) + M_PI;
    return a;
}

double Complex::getReal() { return real; }

double Complex::getImag() { return imag; }

void Complex::add(Complex c) {
    real += c.real;
    imag += c.imag;
}

void Complex::sub(Complex c) {
    real -= c.real;
    imag -= c.imag;
}

void Complex::mult(Complex c) {
    real = (real * c.real) - (imag * c.imag);
    imag = (real * c.imag) + (imag * c.real);
}

void Complex::div(Complex c) {
    real = ((real * c.real) + (imag * c.imag)) / ((c.real * c.real) + (c.imag * c.imag));
    imag = ((imag * c.real) - (real * c.imag)) / ((c.real * c.real) + (c.imag * c.imag));
}

// Returns the conjugate of the complex number.
Complex Complex::coniug() {
    if (imag == 0) {
        throw std::invalid_argument{"Complex::coniug() expects a non-zero imaginary part."};
    }
    return Complex(real, -imag);
}
