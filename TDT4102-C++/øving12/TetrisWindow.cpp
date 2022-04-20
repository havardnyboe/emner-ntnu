#include "TetrisWindow.h"

const map<TetrominoType, Color> colorMap{
    {TetrominoType::J, Color::blue},
    {TetrominoType::L, 91},
    {TetrominoType::T, Color::magenta},
    {TetrominoType::S, Color::green},
    {TetrominoType::Z, Color::red},
    {TetrominoType::O, Color::yellow},
    {TetrominoType::I, Color::cyan},
    {TetrominoType::NONE, 49}};

TetrisWindow::TetrisWindow() : AnimationWindow(1000, 100, windowWidth, windowHeight, "Tetris") {
    gridMatrix = vector<vector<TetrominoType>>(windowHeight, vector<TetrominoType>(windowWidth, TetrominoType::NONE));
    // fill the grid with NONE
    for (int i = 0; i < windowHeight / blockSize; i++) {
        for (int j = 0; j < windowWidth / blockSize; j++) {
            gridMatrix[i][j] = TetrominoType::NONE;
        }
    }
    generateRandomTetromino();
}

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while (!should_close()) {
        framesSinceLastTetronimoMove++;
        if (framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            // Kall moveTetrominoDown() her
            moveTetrominoDown();
            /********************************************************/
        }
        handleInput();

        /********************************************************/
        // Kall draw-funksjonene her
        drawMatrixGrid();
        drawCurrentTetromino(currentTetromino, *this);
        /********************************************************/

        next_frame();
    }
}

void TetrisWindow::generateRandomTetromino() {
    TetrominoType t = static_cast<TetrominoType>(rand() % 6 + 2);
    currentTetromino = Tetromino(startingPoint, t);
}

void TetrisWindow::drawMatrixGrid() {
    for (int i = 0; i < windowHeight / blockSize; i++) {
        for (int j = 0; j < windowWidth / blockSize; j++) {
            draw_rectangle({j * blockSize, i * blockSize}, blockSize, blockSize, colorMap.at(gridMatrix[i][j]));
        }
    }
}

void TetrisWindow::drawCurrentTetromino(Tetromino &t, TetrisWindow &tetrisWindow) {
    for (int i = 0; i < t.getMatrixSize(); i++) {
        for (int j = 0; j < t.getMatrixSize(); j++) {
            if (t.blockExist(i, j)) {
                tetrisWindow.draw_rectangle({t.getPosition().x + j * blockSize, t.getPosition().y + i * blockSize},
                                            blockSize, blockSize,
                                            colorMap.at(t.getBlock()));
            }
        }
    }
}

void TetrisWindow::fastenTetromino() {
    for (int i = 0; i < currentTetromino.getMatrixSize(); i++) {
        for (int j = 0; j < currentTetromino.getMatrixSize(); j++) {
            if (currentTetromino.blockExist(i, j)) {
                gridMatrix[(currentTetromino.getPosition().y / blockSize) + i][(currentTetromino.getPosition().x / blockSize) + j] =
                    currentTetromino.getBlock();
            }
        }
    }
}

void TetrisWindow::moveTetrominoDown() {
    currentTetromino.moveDown();
}

void TetrisWindow::handleInput() {
    static bool lastLeftShiftKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastDownKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;

    bool currentLeftShiftKeyState = is_key_down(KeyboardKey::LEFTSHIFT);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);

    if (currentLeftShiftKeyState && !lastLeftShiftKeyState) {
        // currentTetromino.rotateCounterClockwise();
        fastenTetromino();
    }

    if (currentUpKeyState && !lastUpKeyState) {
        currentTetromino.rotateClockwise();
    }

    if (currentDownKeyState && !lastDownKeyState) {
        currentTetromino.moveDown();
    }

    if (currentLeftKeyState && !lastLeftKeyState) {
        currentTetromino.moveLeft();
    }

    if (currentRightKeyState && !lastRightKeyState) {
        currentTetromino.moveRight();
    }

    lastLeftShiftKeyState = currentLeftShiftKeyState;
    lastUpKeyState = currentUpKeyState;
    lastDownKeyState = currentDownKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;

    // Check if the tetromino is colliding with the grid
    for (int i = 0; i < currentTetromino.getMatrixSize(); i++) {
        for (int j = 0; j < currentTetromino.getMatrixSize(); j++) {
            if (currentTetromino.blockExist(i, j)) {
                // Check if the tetromino is colliding with the grid
                if (currentTetromino.getPosition().x + j * blockSize > windowWidth - blockSize ||
                    currentTetromino.getPosition().x + j * blockSize < 0) {
                    currentTetromino.moveToLastPosition();
                }
                // Check if the tetromino is colliding with other blocks
                if (gridMatrix[(currentTetromino.getPosition().y / blockSize) + i][(currentTetromino.getPosition().x / blockSize) + j] != TetrominoType::NONE) {
                    currentTetromino.moveToLastPosition();
                }
                // Check if the tetromino has landed on another tetromino
                for (i = gridMatrix.size() - 1; i >= 0; i--) {
                    for (j = gridMatrix[i].size() - 1; j >= 0; j--) {
                        if (gridMatrix[i][j] != TetrominoType::NONE &&
                            currentTetromino.getPosition().y + i * blockSize == windowHeight - blockSize &&
                            currentTetromino.getPosition().x + j * blockSize == j * blockSize) {
                            fastenTetromino();
                            generateRandomTetromino();
                        }
                    }
                }

                // Fasten the tetromino if it is colliding with the floor
                if (currentTetromino.getPosition().y + (i + 1) * blockSize > windowHeight - blockSize) {
                    fastenTetromino();
                    generateRandomTetromino();
                }
            }
        }
    }
}
