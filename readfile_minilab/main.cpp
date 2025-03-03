#include <iostream>
#include <iomanip>
#include <fstream>

void print(int size, double** matrix, double* vector) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(6) << matrix[i][j] << " ";
        }
        std::cout << "| " << std::setw(6) << vector[i] << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::ifstream input("matrix.txt");

    if (!input.is_open()) {
        std::cout << "Ошибка чтения файла";
        return 1;
    }

    int size;
    input >> size;

    double** matrix = new double*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
    }

    double* vector = new double[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            input >> matrix[i][j];
        }
        input >> vector[i];
    }

    input.close();

    print(size, matrix, vector);

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vector;

    return 0;
}