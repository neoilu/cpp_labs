#include <iostream>
#include "RandomGenerator.h"

int main() {
    int start;
    int end;
    int seed;

    RandomGenerator generator;

    std::cout << "Введите границы разброса через пробел: ";
    std::cin >> start >> end;

    std::cout << "Введите seed генерации: ";
    std::cin >> seed;

    generator.setBounds(start, end);
    generator.setSeed(seed);

    int number = generator.getRandomNumber();

    std::cout << "Ваше число: " << number;

}