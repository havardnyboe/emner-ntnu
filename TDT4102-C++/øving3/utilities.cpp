#include "std_lib_facilities.h"

void clearTerminal() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

int getUserInputInt(string prompt) {
    int i{0};
    std::cout << prompt;
    std::cin >> i;
    return i;
}

int randomWithLimits(int min, int max) {
    return rand() % (max - min + 1) + min;
}