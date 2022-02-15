#include "Blackjack.hpp"

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

int Blackjack::getCardValue(Card &card) {
    int value = 0;
    switch (card.getRank()) {
    case Rank::ace:
        playerHandSum + 11 <= 21 ? value = 11 : value = 1;
        break;
    case Rank::two:
        value = 2;
        break;
    case Rank::three:
        value = 3;
        break;
    case Rank::four:
        value = 4;
        break;
    case Rank::five:
        value = 5;
        break;
    case Rank::six:
        value = 6;
        break;
    case Rank::seven:
        value = 7;
        break;
    case Rank::eight:
        value = 8;
        break;
    case Rank::nine:
        value = 9;
        break;
    case Rank::ten:
    case Rank::jack:
    case Rank::queen:
    case Rank::king:
        value = 10;
        break;
    }
    return value;
}

int Blackjack::getHandScore(vector<Card> &hand) {
    int score = 0;
    for (Card card : hand) {
        score += getCardValue(card);
    }
    return score;
}

int Blackjack::getPlayerHandSum() { return playerHandSum; }
int Blackjack::getDealerHandSum() { return dealerHandSum; }

bool Blackjack::askPlayerDrawCard() {
    char answer;
    cout << "Do you want to draw another card? (y/n) ";
    cin >> answer;
    return tolower(answer) == 'y' ? true : false;
}

void Blackjack::drawPlayerCard() {
    playerHand.push_back(deck.drawCard());
    playerHandSum = getHandScore(playerHand);
    cout << "Player drew " << playerHand.back().toString() << endl;
}

void Blackjack::drawDealerCard() {
    dealerHand.push_back(deck.drawCard());
    dealerHandSum = getHandScore(dealerHand);
}

void Blackjack::printGameState() {
    clearScreen();
    if (!gameOver) {
        std::cout << "DEALER:" << std::endl
                  << "  " << dealerHand.front().toString() << std::endl
                  << "  + " << dealerHand.size() - 1 << " Card(s)" << std::endl
                  << std::endl;
    } else {
        std::cout << "DEALER:" << std::endl;
        for (Card card : dealerHand) {
            std::cout << "  " << card.toString() << std::endl;
        }
        std::cout << "  SUM: " << dealerHandSum << std::endl;
    }
    std::cout << "PLAYER:" << std::endl;
    for (Card card : playerHand) {
        std::cout << "  " << card.toString() << std::endl;
    }
    std::cout << "  SUM: " << playerHandSum << std::endl;

    std::cout << "  " << endMessage << std::endl;
}

void Blackjack::shuffleDeck() { deck.shuffle(); }

void playBlackjack(Blackjack &game) {
    game.shuffleDeck();
    game.drawPlayerCard();
    game.drawPlayerCard();
    game.drawDealerCard();
    game.drawDealerCard();
    game.printGameState();
    while (game.getPlayerHandSum() < 21 && game.askPlayerDrawCard()) {
        game.drawPlayerCard();
        game.printGameState();
    }
    while (game.getDealerHandSum() < 17) {
        game.drawDealerCard();
        game.printGameState();
    }
    if (game.getPlayerHandSum() > 21) {
        game.endMessage = "Player busted!";
        game.gameOver = true;
        game.printGameState();
    } else if (game.getDealerHandSum() > 21) {
        game.endMessage = "Dealer busted!";
        game.gameOver = true;
        game.printGameState();
    } else if (game.getPlayerHandSum() > game.getDealerHandSum()) {
        game.endMessage = "Player wins!";
        game.gameOver = true;
        game.printGameState();
    } else if (game.getPlayerHandSum() < game.getDealerHandSum()) {
        game.endMessage = "Dealer wins!";
        game.gameOver = true;
        game.printGameState();
    } else {
        game.endMessage = "It's a tie!";
        game.gameOver = true;
        game.printGameState();
    }
}