#pragma once

class Complex {

    private:

        double Re;
        double Im;

    public:
        Complex(double _Re, double _Im);

        ~Complex();

        double getRe();
        double getIm();

        void print();
           
};