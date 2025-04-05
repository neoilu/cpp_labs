#include <iostream>
#include <algorithm>
#include <cmath>
#include "Triangle.h"


int main() {
    double sideA;
    double sideB;
    double sideC;

    std::cout << "Ввеедите стороны треугольника: ";
    std::cin >> sideA >> sideB >> sideC;

    Triangle triangle(sideA, sideB, sideC);


    if (triangle.isExists()) {
        std::cout << "Треугольник существует" << std::endl;
    }
    else {
        std::cout << "Треугольник не существует" << std::endl;
        return -1;
    }


    if (triangle.isRightAngeled()) {
        std::cout << "Треугольник прямоугольный" << std::endl;
    }
    else {
        std::cout << "Треугольник не прямоугольный" << std::endl;
    }


    std::cout << "Площадь треугольника: " << triangle.area() << std::endl;

    return 0;
    
}
