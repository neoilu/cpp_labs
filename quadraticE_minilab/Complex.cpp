#include "Complex.h"
#include <iostream>


Complex::Complex(double _Re, double _Im) {
    Re = _Re;
    Im = _Im;
};

Complex::~Complex() {
}; 

void Complex::print() {
    std::cout << Re;
    if (Im != 0) {
        std::cout << (Im < 0 ? " - " : " + ") << std::abs(Im) << "i";
    }
    std::cout << std::endl;
};