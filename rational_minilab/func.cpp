#include "Rational.h"  

Rational solve(const Rational& num1, const Rational& num2, char operation) {
    Rational result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            throw "Неверная операция!";
    }

    return result;
}
