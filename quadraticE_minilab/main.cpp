#include <iostream>
#include "quadricE.h"


int main() {
    
    double a;
    double b;
    double c;

    std::cout << "Введите коэффициенты квадратного уравнения: ";
    std::cin >> a >> b >> c;

    quadricE equation(a, b, c);

    std::cout << "Исходное уравнение: ";
    equation.print();
    equation.solve();

    return 0;
}