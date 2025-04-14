#include "Rational.h"
#include <numeric>
#include <cmath>   
#include <sstream>
#include <string>

Rational::Rational(int num, int den) : numerator(num), denominator(den) {
    reduce();
}

Rational::Rational(double value) {
    const int precision = 1000000;
    int num = static_cast<int>(round(value * precision));
    int den = precision;
    int gcd = std::gcd(num, den);
    numerator = num / gcd;
    denominator = den / gcd;
}

void Rational::reduce() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {  
        numerator = -numerator;
        denominator = -denominator;
    }
}

Rational Rational::operator+(const Rational& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Rational(num, den);
}

Rational Rational::operator-(const Rational& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Rational(num, den);
}

Rational Rational::operator*(const Rational& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Rational(num, den);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw "Деление на ноль не поддерживается";
    }
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Rational(num, den);
}

int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    if (r.getDenominator() == 1) {
        os << r.getNumerator();  
    } else {
        os << r.getNumerator() << '/' << r.getDenominator();
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    std::string input;
    is >> input;

    if (input.find('.') != std::string::npos) {
        double value = std::stod(input);
        r = Rational(value);
    }

    else if (input.find('/') != std::string::npos) {
        size_t slash = input.find('/');
        int num = std::stoi(input.substr(0, slash));
        int den = std::stoi(input.substr(slash + 1));
        if (den == 0) throw "Знаменатель не может быть нулем!";
        r = Rational(num, den);
    }

    else {
        int num = std::stoi(input);
        r = Rational(num, 1);
    }

    return is;
}
