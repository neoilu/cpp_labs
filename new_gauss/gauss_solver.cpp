#include "gauss_solver.h"
#include <iostream>
#include <cmath>
#include <iomanip>

const double EPSILON = 1e-9;  // Порог для проверки на ноль

void gauss(int size, double** matrix, double* vector) {
    double** originalMatrix = new double*[size]; // Сохранение оригинальной матрицы
    for (int i = 0; i < size; i++) {
        originalMatrix[i] = new double[size];
        for (int j = 0; j < size; j++) {
            originalMatrix[i][j] = matrix[i][j];
        }
    }

    double* originalVector = new double[size];
    for (int i = 0; i < size; i++) {
        originalVector[i] = vector[i];
    }

    for (int i = 0; i < size; i++) {
        // 🔹 **Шаг 1: Поиск главного элемента в колонке**
        int pivot = i;
        for (int k = i + 1; k < size; k++) {
            if (std::fabs(matrix[k][i]) > std::fabs(matrix[pivot][i])) {
                pivot = k;
            }
        }

        // 🔹 **Шаг 2: Проверка на вырожденность матрицы**
        if (std::fabs(matrix[pivot][i]) < EPSILON) {
            std::cout << "Ошибка: СЛАУ несовместна или имеет бесконечно много решений" << std::endl;
            return;
        }

        // 🔹 **Шаг 3: Обмен строками, если необходимо**
        if (i != pivot) {
            std::swap(matrix[i], matrix[pivot]);
            std::swap(vector[i], vector[pivot]);
        }

        // 🔹 **Шаг 4: Приведение главного элемента к 1**
        double lead = matrix[i][i];
        for (int j = i; j < size; j++) {
            matrix[i][j] /= lead;
        }
        vector[i] /= lead;

        // 🔹 **Шаг 5: Обнуление элементов под главной диагональю**
        for (int k = i + 1; k < size; k++) {
            double factor = matrix[k][i];
            for (int j = i; j < size; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
            vector[k] -= factor * vector[i];
        }
    }

    // 🔹 **Шаг 6: Обратный ход (нахождение решений)**
    double* solution = new double[size];

    for (int i = size - 1; i >= 0; i--) {
        solution[i] = vector[i];
        for (int j = i + 1; j < size; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }

    // 🔹 **Вывод результата**
    std::cout << "Решение системы:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "x[" << i + 1 << "] = " << std::fixed << std::setprecision(6) << solution[i] << std::endl;
    }

    // 🔹 **Шаг 7: Вычисление и вывод вектора невязки**
    double* residual = new double[size];
    for (int i = 0; i < size; i++) {
        residual[i] = originalVector[i];
        for (int j = 0; j < size; j++) {
            residual[i] -= originalMatrix[i][j] * solution[j];
        }
    }

    std::cout << "\nВектор невязки:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "r[" << i + 1 << "] = " << std::scientific << std::setprecision(6) << residual[i] << std::endl;
    }

    // 🔹 **Очистка памяти**
    delete[] solution;
    delete[] residual;
    delete[] originalVector;
    for (int i = 0; i < size; i++) {
        delete[] originalMatrix[i];
    }
    delete[] originalMatrix;
}
