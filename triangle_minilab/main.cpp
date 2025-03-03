#include <iostream>
#include <algorithm>
#include <cmath>

class Triangle {
    private:

        double sideA;
        double sideB;
        double sideC;

    public:

        Triangle(double p_sideA, double p_sideB, double p_sideC) {
            sideA = p_sideA;
            sideB = p_sideB;
            sideC = p_sideC;
        };


        bool isExists() {
            return 2 * std::max({sideA, sideB, sideC}) < sideA + sideB + sideC;
        };

        bool isRightAngeled() {
            double maxSide = std::max({sideA, sideB, sideC});
            return 2 * maxSide * maxSide == sideA * sideA + sideB * sideB + sideC * sideC;
        };

        double area() {
            double p = (sideA + sideB + sideC) / 2.0;
            return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
        };
};


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
    
}
