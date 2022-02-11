#include "mastermind.h"
#include "AnimationWindow.h"
#include "Graph.h"
#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "uitilities.h"

void playMastermind() {
    int numberOfGuesses{6};

    std::string code{randomizeString(SIZE, 'A', 'A' + LETTERS - 1)};
    std::string guess;

    guess = readInputToString(SIZE, 'A', 'A' + LETTERS - 1);
    --numberOfGuesses;

    while (checkCharactersAndPosition(code, guess) < SIZE || numberOfGuesses > 0) {
        clear();
        std::cout << "Du gjettet: " << guess
                  << std::endl
                  << "Du hadde " << checkCharacters(code, guess) << " bokstaver riktig"
                  << std::endl
                  << "Du hadde " << checkCharactersAndPosition(code, guess) << " boksstaver riktig og på riktig plass"
                  << std::endl;
        if (numberOfGuesses > 0) {
            std::cout << "Du har " << numberOfGuesses << " forsøk igjen" << std::endl;
        } else {
            std::cout << "Du har ikke flere forsøk igjen. Koden var: " << code << std::endl;
            break;
        }
        guess = readInputToString(SIZE, 'A', 'A' + LETTERS - 1);
        --numberOfGuesses;
        if (guess == code) {
            clear();
            std::cout << "Du vant! Koden var: " << code << std::endl;
        }
    }
}

void playMastermindVisual() {
    // int numberOfGuesses{6};

    // std::string code{randomizeString(SIZE, 'A', 'A' + LETTERS - 1)};
    // std::string guess;

    // MastermindWindow mwin{900, 20, winW, winH, SIZE, "Mastermind"};
    AnimationWindow mwin{};
    mwin.wait_for_close();
    mwin.draw_rectangle(Point{10, 10}, padX * 10, padY * 10);
    // mwin.setCodeHidden(false);

    // guess = mwin.getInput(SIZE, 'A', 'A' + LETTERS - 1);
    // addGuess(mwin, guess, 'A');
    // mwin.redraw();
    // --numberOfGuesses;

    // while (checkCharactersAndPosition(code, guess) < SIZE || numberOfGuesses > 0) {
    //     clear();
    //     std::cout << "Du gjettet: " << guess
    //               << std::endl
    //               << "Du hadde " << checkCharacters(code, guess) << " bokstaver riktig"
    //               << std::endl
    //               << "Du hadde " << checkCharactersAndPosition(code, guess) << " boksstaver riktig og på riktig plass"
    //               << std::endl;
    //     if (numberOfGuesses > 0) {
    //         std::cout << "Du har " << numberOfGuesses << " forsøk igjen" << std::endl;
    //     } else {
    //         std::cout << "Du har ikke flere forsøk igjen. Koden var: " << code << std::endl;
    //         break;
    //     }
    //     guess = mwin.getInput(SIZE, 'A', 'A' + LETTERS - 1);
    //     mwin.redraw();
    //     --numberOfGuesses;
    //     if (guess == code) {
    //         clear();
    //         std::cout << "Du vant! Koden var: " << code << std::endl;
    //     }
    // }
}

int checkCharactersAndPosition(std::string code, std::string guess) {
    int correctCharacters{0};
    for (int i{0}; i < SIZE; ++i) {
        if (code.at(i) == guess.at(i)) {
            ++correctCharacters;
        }
    }
    return correctCharacters;
}

int checkCharacters(std::string code, std::string guess) {
    int correctCharacters{0};
    for (int i{0}; i < SIZE; ++i) {
        for (int j{0}; j < SIZE; ++j) {
            if (code.at(i) == guess.at(j)) {
                ++correctCharacters;
                break;
            }
        }
    }
    return correctCharacters;
}
