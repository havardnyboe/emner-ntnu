#pragma once
#include "AnimationWindow.h"
#include "GUI.h"
#include "Tetromino.h"
#include <atomic>

constexpr int blockSize{30};
constexpr int windowWidth{blockSize * 20};
constexpr int windowHeight{blockSize * 30};
constexpr Point startingPoint{windowWidth / 2, 0};

class TetrisWindow : public AnimationWindow {

  public:
    TetrisWindow();
    void run();
    void generateRandomTetromino();
    void drawMatrixGrid();
    void drawCurrentTetromino(Tetromino &t, TetrisWindow &tetrisWindow);
    void fastenTetromino();
    void moveTetrominoDown();

  private:
    vector<vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;

    void handleInput();
};
