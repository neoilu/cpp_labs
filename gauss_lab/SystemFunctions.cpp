#include "SystemFunctions.h"

SystemFunctions::SystemFunctions(int p_size, double** p_matrix, double* p_vector) {
    size = p_size;

    matrix = new double*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = p_matrix[i][j];
        }
    }

    vector = new double[size];
    for (int i = 0; i < size; i++) {
        vector[i] = p_vector[i];
    }
}

void SystemFunctions::print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << std::fixed << std::setprecision(2) << std::setw(6) << matrix[i][j] << " ";
            }
            std::cout << "| " << std::setw(6) << vector[i] << std::endl;
        }
        std::cout << std::endl;
    }

void SystemFunctions::gauss() {
    for (int i = 0; i < size; i++) {
        int row = i;
        for (int k = i + 1; k < size; k++) {
            if (std::abs(matrix[k][i]) > std::abs(matrix[row][i])) {
                row = k;
            }
        }

        if (std::abs(matrix[row][i]) < 1e-9) {
            std::cout << "Ошибка: СЛАУ несовместна или имеет бесконечно много решений" << std::endl;
            return;
        }

        std::swap(matrix[i], matrix[row]);
        std::swap(vector[i], vector[row]);

        double lead = matrix[i][i];
        for (int j = 0; j < size; j++) {
            matrix[i][j] /= lead;
            if (std::abs(matrix[i][j]) < 1e-9) matrix[i][j] = 0.0;
        }
        vector[i] /= lead;

        for (int k = 0; k < size; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < size; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
                vector[k] -= factor * vector[i];
            }
        }

        std::cout << "Шаг решения:" << std::endl;
        print();
    }

    std::cout << "Решение:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "x[" << i + 1 << "] = " << vector[i] << std::endl;
    }
}

bool SystemFunctions::determinant() {
    double** copiedMatrix = copyMatrix();
    double determinant = 1;

    for (int i = 0; i < size; i++) {
        int pivot = i;
        for (int j = i + 1; j < size; j++) {
            if (std::abs(copiedMatrix[j][i]) > std::abs(copiedMatrix[pivot][i])) {
                pivot = j;
            }
        }

        if (std::abs(copiedMatrix[pivot][i]) < 1e-9) {
            for (int k = 0; k < size; k++) delete[] copiedMatrix[k];
            delete[] copiedMatrix;
            return false;
        }

        if (i != pivot) {
            std::swap(copiedMatrix[i], copiedMatrix[pivot]);
            determinant = -determinant; 
        }

        determinant *= copiedMatrix[i][i];

        for (int j = i + 1; j < size; j++) {
            double factor = copiedMatrix[j][i] / copiedMatrix[i][i];
            for (int k = i; k < size; k++) {
                copiedMatrix[j][k] -= factor * copiedMatrix[i][k];
            }
        }
    }

    for (int i = 0; i < size; i++) delete[] copiedMatrix[i];
    delete[] copiedMatrix;

    return determinant != 0;
}

double** SystemFunctions::copyMatrix() {
        double** newMatrix = new double*[size];
        for (int i = 0; i < size; i++) {
            newMatrix[i] = new double[size];
            for (int j = 0; j < size; j++) {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        return newMatrix;
    }