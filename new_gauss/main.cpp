#include <iostream>
#include <cmath>
#include <fstream>
#include "gauss_solver.h"

int countNumbersInFile() {
    std::ifstream input("matrix.txt");
    if (!input.is_open()) return -1;

    double num;
    int count = 0;
    while (input >> num) count++;

    input.close();
    return count;
}

int main() {
    std::cout << "\tМеню\n" << std::endl
              << "Выберите способ задания матрицы:" << std::endl
              << "1. Ввести СЛАУ вручную" << std::endl
              << "2. Прочитать СЛАУ из файла" << std::endl
              << "3. Ввести случайные числа" << std::endl;

    int choice;
    std::cin >> choice;

    int size = 0;
    double** matrix = nullptr;
    double* vector = nullptr;

    switch(choice) {
        case 1: {
            std::cout << "Введите размер матрицы: ";
            std::cin >> size;

            if (size < 0) {
                std::cout << "Некорректный ввод" << std::endl;
                return -1;
            }

            matrix = new double*[size];
            vector = new double[size];
            for (int i = 0; i < size; i++) {
                matrix[i] = new double[size];
            }

            std::cout << "Введите коэффициенты системы уравнений (построчно), последнее число - вектор:" << std::endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    std::cin >> matrix[i][j];
                }
                std::cin >> vector[i];
            }
            break;
        }
        case 2: {
            std::ifstream input("matrix.txt");

            if (!input.is_open()) {
                std::cout << "Ошибка чтения файла" << std::endl;
                return 1;
            }
            else if (input.peek() == EOF) {
                std::cout << "Файл пуст";
                return -1;
            }

            input >> size;

            if (countNumbersInFile() - 1 != size * (size + 1)) {
                std::cout << "Некорректный ввод" << std::endl;
                return -1;
            }

            matrix = new double*[size];
            vector = new double[size];
            for (int i = 0; i < size; i++) {
                matrix[i] = new double[size];
            }

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    input >> matrix[i][j];
                }
                input >> vector[i];
            }

            input.close();
            break;
        }
        case 3: {
            std::cout << "Введите размер матрицы: ";
            std::cin >> size;

            if (size < 0) {
                std::cout << "Некорректный ввод" << std::endl;
                return -1;
            }

            matrix = new double*[size];
            vector = new double[size];
            for (int i = 0; i < size; i++) {
                matrix[i] = new double[size];
            }

            srand(time(0));

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[i][j] = rand()%1000;
                }
                vector[i] = rand()%1000;
            }

            break;
        }
    }

    // Вызов метода Гаусса для решения системы
    gauss(size, matrix, vector);

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vector;

    return 0;
}
