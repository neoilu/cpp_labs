#include "utils.h"

void print(int size, double** matrix, double* vector) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(6) << matrix[i][j] << " ";
        }
        std::cout << "| " << std::setw(6) << vector[i] << std::endl;
    }
};

int countNumbersInFile() {
    std::ifstream input("matrix.txt");

    if (!input.is_open()) {
        return -1;
    }

    double num;
    int count = 0;

    while (input >> num) {
        count++;
    }

    input.close();
    return count;
};

bool readFile(int& size, double**& matrix, double*& vector) {
    std::ifstream input("matrix.txt");

    if (!input.is_open()) {
        std::cout << "Ошибка чтения файла" << std::endl;
        return false;
    }
    else if (input.peek() == EOF) {
        std::cout << "Файл пуст" << std::endl;
        return false;
    }

    input >> size;

    if (countNumbersInFile() - 1 != size * (size + 1)) {
        std::cout << "Некорректный ввод" << std::endl;
        return false;
    }

    matrix = new double*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
    }

    vector = new double[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            input >> matrix[i][j];
        }
        input >> vector[i];
    }

    input.close();
    return true;
};

void freeMemory(int size, double** matrix, double* vector) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] vector;
};
