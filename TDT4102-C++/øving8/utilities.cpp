#include "utilities.h"

// CLASS: Matrix
Matrix::Matrix(int nRows, int nColumns) {
    assert(nRows > 0 && nColumns > 0);
    rows = nRows;
    columns = nColumns;
    matrix = new double *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows) {
    assert(nRows > 0);
    for (int i = 0; i < rows; i++) {
        matrix[i][i] = 1;
    }
}

Matrix::Matrix(const Matrix &m) {
    rows = m.rows;
    columns = m.columns;
    matrix = new double *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double Matrix::get(int row, int column) const {
    assert(row >= 0 && row < rows && column >= 0 && column < columns);
    return matrix[row][column];
}

void Matrix::set(int row, int column, double value) {
    assert(row >= 0 && row < rows && column >= 0 && column < columns);
    matrix[row][column] = value;
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            os << m.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

Matrix Matrix::operator=(const Matrix &m) {
    if (this != &m) {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        rows = m.rows;
        columns = m.columns;
        matrix = new double *[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[columns];
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+=(const Matrix &m) {
    assert(rows == m.rows && columns == m.columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] += m.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &m) {
    assert(rows == m.rows && columns == m.columns);
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    return result;
}

// Program functions
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void fillInFibonacciNumbers(int *result, int length) {
    int a{0}, b{1}, c{0};
    result[0] = a;
    result[1] = b;

    for (int i = 2; i < length; i++) {
        c = a + b;
        result[i] = c;
        a = b;
        b = c;
    }
}

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << std::endl;
    }
}

void createFibonacci() {
    std::cout << "Hvor mange tall skal genereres?" << std::endl;
    int *length = new int(0);
    std::cin >> *length;
    int *result = new int[*length];

    fillInFibonacciNumbers(result, *length);
    printArray(result, *length);

    delete[] result;
    delete length;
}

void addValueToMatrix(Matrix &m) {
    int row{0}, column{0};
    double val{0};
    std::cout << "Hvilken rad vil du legge til verdi i? (0-" << m.getRows() - 1 << "): ";
    std::cin >> row;
    std::cout << "Hvilken kolonne vil du legge til verdi i? (0-" << m.getColumns() - 1 << "): ";
    std::cin >> column;
    std::cout << "Hva vil du legge til? ";
    std::cin >> val;
    m.set(row, column, val);
    std::cout << m << std::endl;
}