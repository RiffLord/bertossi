/**
 * @file    debugpp.cpp
 * @author  Bruno Pezer
 * @brief   Testing the classes implemented in data_structures.h
 * @version 0.2
 * @date    2023-07-04
 *
 * @copyright NO Copyright !(c) 2023
 *
 */
#ifdef __linux__
    #include "../data_structures.h"
#elif _WIN32
    #include "..\data_structures.h"
#else
    #error Platform not supported
#endif

int main(int argc, char const *argv[]) {
    Complex c;
    std::cout << "c.getReal():" << c.getReal() << std::endl;
    std::cout << "c.getImag():" << c.getImag() << std::endl;
    //c.coniug(); // Causes an expected exception to be thrown.
    //c.arg();    // Causes an expected exception to be thrown.
    Complex d(3, -4);
    std::cout << "d.getReal():" << d.getReal() << std::endl;
    std::cout << "d.getImag():" << d.getImag() << std::endl;

    std::cout << "\nPress Enter to continue... ";
    std::cin.ignore();
    std::cout << std::endl;

    std::cout << "d.mod(): " << d.mod() << std::endl;
    std::cout << "d.arg(): " << d.arg() << std::endl;

    std::cout << "c + d = (" << c.getReal() << " + " << d.getReal() << ", " << c.getImag() << " + " << d.getImag() << ")" << std::endl;
    c.add(d);
    std::cout << "c + d = " << c << std::endl;

    std::cout << "\nPress Enter to continue... ";
    std::cin.ignore();
    std::cout << std::endl;

    Complex e = Complex(12, 9);

    std::cout << "c - e = (" << c.getReal() << " - " << e.getReal() << ", " << c.getImag() << " - " << e.getImag() << ")" << std::endl;
    c.sub(e);
    std::cout << "c - e = " << c << std::endl;

    std::cout << "\nPress Enter to continue... ";
    std::cin.ignore();
    std::cout << std::endl;

    c.mult(e);
    std::cout << "c × e = " << c << std::endl;

    e.div(d);
    std::cout << "e ÷ d = " << e << std::endl;

    std::cout << "\nPress Enter to continue... ";
    std::cin.ignore();
    std::cout << std::endl;

    Complex cCon = c.coniug();
    std::cout << "c.coniug(): " << cCon << std::endl;

    return 0;
}

