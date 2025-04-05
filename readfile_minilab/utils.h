#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

void print(int size, double** matrix, double* vector);
int countNumbersInFile();
bool readFile(int& size, double**& matrix, double*& vector);
void freeMemory(int size, double** matrix, double* vector);
