#include "Blackjack.hpp"

int main() {

    srand(time(NULL)); // seed the random number generator

    Blackjack blackjack;

    playBlackjack(blackjack);
}

/* Possible improvements:
    - Add ability to have more than one deck of cards
    - Add ability to have more than one player (i.e. make a class for the player)
    - Make a class for the dealer
    - Declare end of game with a switch statement
    - Add ability to double down
    - Add ability to split
    - Add ability to bet money
    - Add ability to save/load game
*/