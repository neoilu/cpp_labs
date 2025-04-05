#include "utils.h"

int main() {
    int size;
    double** matrix;
    double* vector;

    if (!readFile(size, matrix, vector)) {
        return -1;
    }

    std::cout << "Матрица из файла: " << std::endl;
    print(size, matrix, vector);

    freeMemory(size, matrix, vector);

    return 0;
};
