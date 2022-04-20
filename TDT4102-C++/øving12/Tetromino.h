#pragma once
#include "Graph.h"

enum class TetrominoType { NONE = 0,
                           J,
                           L,
                           T,
                           S,
                           Z,
                           O,
                           I };

class Tetromino {
  public:
    static constexpr int blockSize{30};

    Tetromino(Point startingPoint, TetrominoType tetType);
    Tetromino();

    void rotateClockwise();
    void rotateCounterClockwise();
    void moveToLastPosition();
    void moveDown();
    void moveLeft();
    void moveRight();

    bool blockExist(int row, int column);
    TetrominoType getBlock();
    int getMatrixSize();
    Point getPosition();

    void printTetromino();

  private:
    int matrixSize;
    Point topLeftCorner;
    Point lastTopLeftCorner;
    TetrominoType tetrominoType;
    vector<vector<TetrominoType>> blockMatrix;
    vector<vector<TetrominoType>> lastBlockMatrix;
};
