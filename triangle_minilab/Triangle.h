#pragma once

#include <algorithm>
#include <cmath>

class Triangle {
    private:
    
        double sideA;
        double sideB;
        double sideC;

    public:

        Triangle(double p_sideA, double p_sideB, double p_sideC);

        ~Triangle();


        bool isExists();
        bool isRightAngeled();
        double area();
};