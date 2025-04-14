#pragma once
#include <iostream>
#include <stdexcept>
#include <numeric> 

class Rational {
private:
    int numerator;
    int denominator;

    void reduce();

public:
    Rational(int num = 0, int den = 1);
    Rational(double value);

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    int getNumerator() const;
    int getDenominator() const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};
