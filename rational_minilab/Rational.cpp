#include "Rational.h"
#include <numeric>

Rational::Rational(int num, int den) : numerator(num), denominator(den) {
    reduce();
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
    is >> r.numerator >> r.denominator;
    if (r.denominator == 0) {
        throw "Знаменатель не может быть нулем!";
    }
    r.reduce();
    return is;
}
