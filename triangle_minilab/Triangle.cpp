#include "Triangle.h"

Triangle::Triangle(double p_sideA, double p_sideB, double p_sideC) {
    sideA = p_sideA;
    sideB = p_sideB;
    sideC = p_sideC;
};

Triangle::~Triangle() {
};

bool Triangle::isExists() {
    return 2 * std::max({sideA, sideB, sideC}) < sideA + sideB + sideC;
};

bool Triangle::isRightAngeled() {
    double maxSide = std::max({sideA, sideB, sideC});
    return 2 * maxSide * maxSide == sideA * sideA + sideB * sideB + sideC * sideC;
};

double Triangle::area() {
    double p = (sideA + sideB + sideC) / 2.0;
    return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
};