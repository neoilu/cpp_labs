#include <iostream>
#include <vector>
#include "RandomGenerator.h"

int main() {
    int start;
    int end;
    long int seed;
    int length;

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

        std::cout << "Введите длину последовательности: ";
        if (!(std::cin >> length) || length <= 0) {
            throw "Длина должна быть положительным целым числом!";
        }

        generator.setBounds(start, end);
        generator.setSeed(seed);

        int number = generator.getRandomNumber();

        std::vector<int> sequence = generator.getRandomSequence(length);

        std::cout << "Ваше число: " << number << std::endl;

        std::cout << "Случайная последовательность: ";
        for (int num : sequence) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

    } catch (const char* e) {
        std::cout << "Ошибка: " << e << std::endl;
    }

    return 0;
}
