#pragma once
#include "CardDeck.hpp"

class Blackjack {
  private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum{0};
    int dealerHandSum{0};

    bool isAce(Card &card) {
        return card.getRank() == Rank::ace ? true : false;
    };

  public:
    bool gameOver = false;
    string endMessage = "";
    int getCardValue(Card &card);
    int getHandScore(vector<Card> &hand);
    int getPlayerHandSum();
    int getDealerHandSum();
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void printGameState();
    void shuffleDeck();
};

void playBlackjack(Blackjack &game);