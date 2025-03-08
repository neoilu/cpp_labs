#include "quadricE.h"
#include <iostream>
#include <cmath>
#include "Complex.h"

quadricE::quadricE(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
}

void quadricE::print() {
    if (a != 0) {
        std::cout << a << "x^2";
    }

    if (b != 0) {
        if (a != 0) {
            std::cout << " " << (b < 0 ? "- " : "+ ") << std::abs(b) << "x";
        } else {
            std::cout << b << "x";
        }
    }

    if (c != 0) {
        if (a != 0 || b != 0) {
            std::cout << " " << (c < 0 ? "- " : "+ ") << std::abs(c);
        } else {
            std::cout << c;
        }
    }

    std::cout << " = 0" << std::endl;
}

void quadricE::solve() {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                std::cout << "Бесконечно решений" << std::endl;
            } else {
                std::cout << "Нет решений" << std::endl;
            }
        } else {
            double root = -c / b;
            std::cout << "Линейное уравнение, единственныйй корень: " << root << std::endl;
        }
        return;
    }   

    double discriminant = b * b - 4 * a * c;
    double realPart = 0;
    double imaginaryPart = 0;

    if (discriminant >= 0) {
        realPart = std::sqrt(discriminant);
    } else {
        imaginaryPart = std::sqrt(-discriminant);
    }

    Complex root1((-b + realPart) / (2.0 * a), imaginaryPart / (2.0 * a));
    Complex root2((-b - realPart) / (2.0 * a), -imaginaryPart / (2.0 * a));

    std::cout << "x1 = ";
    root1.print();
    std::cout << "x2 = ";
    root2.print();
};