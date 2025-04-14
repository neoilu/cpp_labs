#include <iostream>
#include "Rational.h"
#include "func.h"

int main() {
    try {
        Rational num1, num2;
        char operation;

        std::cout << "Введите первое число: ";
        std::cin >> num1;

        std::cout << "Введите второе число: ";
        std::cin >> num2;

        std::cout << "Выберите операцию (+, -, *, /): ";
        std::cin >> operation;

        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            std::cout << "Неверная операция!" << std::endl;
            return 1;
        }

        Rational result = solve(num1, num2, operation);

        std::cout << "Результат: " << result << std::endl;
    } catch (const char* e) {
        std::cout << "Ошибка: " << e << std::endl;
    }

    return 0;
}
