#include "Blackjack.hpp"

int main() {

    srand(time(nullptr)); // seed the random number generator

    Player player;
    Dealer dealer;
    Blackjack game(player, dealer);

    game.playBlackjack(player, dealer);

    return 0;
}