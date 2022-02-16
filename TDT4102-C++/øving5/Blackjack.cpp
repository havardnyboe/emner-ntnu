#include "Blackjack.hpp"

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// CLASS: Player

Player::Player() {
    drawMoreCards = true;
    handSum = 0;
}

bool Player::askDrawCard() {
    if (!drawMoreCards) {
        return false;
    }
    char answer;
    std::cout << "Do you want to draw another card? (y/n): ";
    std::cin >> answer;
    tolower(answer) == 'y' ? drawMoreCards = true : drawMoreCards = false;
    return drawMoreCards;
}

int Player::getCardValue(Card &card) {
    int value = 0;
    switch (card.getRank()) {
    case Rank::ace:
        handSum + 11 <= 21 ? value = 11 : value = 1;
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

int Player::countHandScore() {
    int score = 0;
    // flytter alle ess til enden av hånden for å kunne regne ut score uten å få feil
    for (int i = 0; i < hand.size(); i++) {
        if (hand.at(i).getRank() == Rank::ace) {
            Card temp = hand[i];
            hand.erase(hand.begin() + i);
            hand.push_back(temp);
        }
    }
    for (Card card : hand) {
        score += getCardValue(card);
    }
    return score;
}

void Player::drawCard(CardDeck &deck) {
    Card card = deck.drawCard();
    hand.push_back(card);
    handSum = countHandScore();
}

void Player::printHand() {
    std::cout << "Your hand: \n";
    for (Card card : hand) {
        std::cout << "  " << card.toString() << std::endl;
    }
    std::cout << "  Your hand sum: " << countHandScore() << std::endl
              << std::endl;
}

// CLASS: Dealer

void Dealer::printHand(bool showDealerHand) {
    std::cout << "Dealer's hand: \n";
    if (!showDealerHand) {
        std::cout << "  " << hand.front().toString() << " \n  [hidden]" << std::endl
                  << std::endl;
    } else {
        for (Card card : hand) {
            std::cout << "  " << card.toString() << std::endl;
        }
        std::cout << "  Dealer's hand sum: " << countHandScore() << endl;
    }
}

// CLASS: Blackjack

Blackjack::Blackjack(Player &player, Dealer &dealer) {
    gameOver = false;
    endMessage = "\n";
    deck.shuffle();
    player.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);
    dealer.drawCard(deck);
}

void Blackjack::printGameState(Player &player, Dealer &dealer, bool gameOver) {
    clearScreen();
    player.printHand();

    dealer.printHand(gameOver);
    if (gameOver) {
        std::cout << endMessage << std::endl;
    }
}

void Blackjack::playBlackjack(Player &player, Dealer &dealer) {
    printGameState(player, dealer, gameOver);

    while (player.countHandScore() < 21 && player.askDrawCard()) {
        player.drawCard(deck);
        printGameState(player, dealer, gameOver);
    }

    if (player.countHandScore() > 21) {
        endMessage += "You busted! Dealer wins!";
        gameOver = true;
    } else if (player.countHandScore() == 21) {
        endMessage += "You got 21!";
        gameOver = true;
    } else {
        while (dealer.countHandScore() < 17) {
            dealer.drawCard(deck);
        }
        if (dealer.countHandScore() > 21) {
            endMessage += "Dealer busted! You win!";
            gameOver = true;
        } else if (dealer.countHandScore() > player.countHandScore()) {
            endMessage += "Dealer wins!";
            gameOver = true;
        } else if (dealer.countHandScore() < player.countHandScore()) {
            endMessage += "You win!";
            gameOver = true;
        } else {
            endMessage += "It's a tie!";
            gameOver = true;
        }
    }

    printGameState(player, dealer, gameOver);
}