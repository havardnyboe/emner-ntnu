#pragma once
#include <iostream>
#include <string>

void clearScreen();

class Matrix {
    int rows;
    int columns;
    double **matrix;

  public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    Matrix(const Matrix &m);
    ~Matrix();

    double get(int row, int column) const;
    void set(int row, int column, double value);

    int getRows() const;
    int getColumns() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
    Matrix operator=(const Matrix &m);
    Matrix operator+=(const Matrix &m);
    Matrix operator+(const Matrix &m);
};

void fillInFibonacciNumbers(int *result, int length);
void printArray(int *array, int length);
void createFibonacci();
void addValueToMatrix(Matrix &m);