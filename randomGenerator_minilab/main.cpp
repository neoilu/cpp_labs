#include <iostream>
#include "RandomGenerator.h"

int main() {
    int start;
    int end;
    int seed;

    RandomGenerator generator;
    try {
        std::cout << "Введите границы разброса через пробел: ";
        if (!(std::cin >> start >> end)) {
            throw "Границы должны быть целыми числами!";
        }

        std::cout << "Введите seed генерации: ";
        if (!(std::cin >> seed)) {
            throw "Seed должен быть целым числом!";
        }

        generator.setBounds(start, end);
        generator.setSeed(seed);

        int number = generator.getRandomNumber();

        std::cout << "Ваше число: " << number;
    } catch (const char* e) {
        std::cout << "Ошибка: " << e;
    }
}