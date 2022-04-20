#include "TetrisWindow.h"
#include "Tetromino.h"

int main() {
    srand(unsigned(time(nullptr)));

    /********************************************************/
    // Opprett vindu her
    TetrisWindow tetrisWindow = TetrisWindow();
    /********************************************************/
    // kall run på det her
    tetrisWindow.run();

    tetrisWindow.wait_for_close();
}
