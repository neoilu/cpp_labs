#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>


class SystemFunctions {

private:

    int size;
    double** matrix;
    double* vector;

public:
    SystemFunctions(int p_size, double** p_matrix, double* p_vector);

    ~SystemFunctions() {
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] vector;
    }

    void print();
    void gauss();
    bool determinant();
    double** copyMatrix();
};