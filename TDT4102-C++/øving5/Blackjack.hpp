#pragma once
#include "CardDeck.hpp"

class Player {
  protected:
    vector<Card> hand;
    bool drawMoreCards;
    int handSum{0};

  public:
    Player();
    bool askDrawCard();
    int getCardValue(Card &card);
    int countHandScore();
    void drawCard(CardDeck &deck);
    void printHand();
};

class Dealer : public Player {
  public:
    void printHand(bool showDealerHand);
};

class Blackjack {
  private:
    CardDeck deck;

  public:
    Blackjack(Player &player, Dealer &dealer);
    bool gameOver;
    string endMessage;
    void printGameState(Player &player, Dealer &dealer, bool gameOver);
    void playBlackjack(Player &player, Dealer &dealer);
};

void playBlackjack(Blackjack &game);