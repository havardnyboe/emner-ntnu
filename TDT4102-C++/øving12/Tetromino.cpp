#include "Tetromino.h"

const map<TetrominoType, vector<vector<int>>> initialMatrixMap{

    {TetrominoType::J,
     {{0, 1, 0},
      {0, 1, 0},
      {1, 1, 0}}},
    {TetrominoType::L,
     {{0, 1, 0},
      {0, 1, 0},
      {0, 1, 1}}},
    {TetrominoType::T,
     {{0, 1, 0},
      {1, 1, 1},
      {0, 0, 0}}},
    {TetrominoType::S,
     {{0, 1, 1},
      {1, 1, 0},
      {0, 0, 0}}},
    {TetrominoType::Z,
     {{1, 1, 0},
      {0, 1, 1},
      {0, 0, 0}}},
    {TetrominoType::O,
     {{1, 1},
      {1, 1}}},
    {TetrominoType::I,
     {// Denne er representert som en 6x6 matrise for å få en bedre rotasjonsfunksjonalitet
      {0, 0, 1, 0, 0, 0},
      {0, 0, 1, 0, 0, 0},
      {0, 0, 1, 0, 0, 0},
      {0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}}},
    {TetrominoType::NONE,
     {}}};

Tetromino::Tetromino(Point startingPoint, TetrominoType tetType) : topLeftCorner{startingPoint} {
    matrixSize = initialMatrixMap.at(tetType).size();
    blockMatrix = {};
    for (int i = 0; i < matrixSize; i++) {
        blockMatrix.push_back({});
        for (int j = 0; j < matrixSize; j++) {
            if (initialMatrixMap.at(tetType)[i][j] == 1) {
                blockMatrix[i].push_back(tetType);
            } else {
                blockMatrix[i].push_back(TetrominoType::NONE);
            }
        }
    }
    tetrominoType = tetType;

    printTetromino();
}

Tetromino::Tetromino() {
    topLeftCorner = Point{0, 0};
    matrixSize = 0;
    tetrominoType = TetrominoType::NONE;

    printTetromino();
}

void Tetromino::rotateCounterClockwise() {
    lastTopLeftCorner = topLeftCorner;
    lastBlockMatrix = blockMatrix;
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < row; column++) {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre raden
    for (int row = 0; row < matrixSize / 2; row++) {
        for (int column = 0; column < matrixSize; column++) {
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize - row - 1][column]);
        }
    }

    printTetromino();
}

void Tetromino::rotateClockwise() {
    lastTopLeftCorner = topLeftCorner;
    lastBlockMatrix = blockMatrix;
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < row; column++) {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre kolonnen
    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < matrixSize / 2; column++) {
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize - column - 1]);
        }
    }

    printTetromino();
}

void Tetromino::moveToLastPosition() {
    blockMatrix = lastBlockMatrix;
    topLeftCorner = lastTopLeftCorner;
    printTetromino();
}

void Tetromino::moveDown() {
    lastTopLeftCorner = topLeftCorner;
    lastBlockMatrix = blockMatrix;
    topLeftCorner.y += blockSize;
    printTetromino();
}

void Tetromino::moveLeft() {
    lastTopLeftCorner = topLeftCorner;
    lastBlockMatrix = blockMatrix;
    topLeftCorner.x -= blockSize;
    printTetromino();
}

void Tetromino::moveRight() {
    lastTopLeftCorner = topLeftCorner;
    lastBlockMatrix = blockMatrix;
    topLeftCorner.x += blockSize;
    printTetromino();
}

bool Tetromino::blockExist(int row, int column) {
    if (row < 0 || row >= matrixSize || column < 0 || column >= matrixSize) {
        return false;
    }
    return blockMatrix[row][column] != TetrominoType::NONE;
}

TetrominoType Tetromino::getBlock() {
    return tetrominoType;
}

int Tetromino::getMatrixSize() {
    return matrixSize;
}

Point Tetromino::getPosition() {
    return topLeftCorner;
}

void Tetromino::printTetromino() {
    cout << "matrixSize: " << matrixSize << endl;
    cout << "blockMatrix: " << endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << static_cast<int>(blockMatrix[i][j]) << " ";
        }
        cout << endl;
    }
    cout << "topLeftCorner: " << topLeftCorner.x << " " << topLeftCorner.y << endl;
}