#pragma once
#include "Card.hpp"

class CardDeck {
  private:
    vector<Card> cards{};

  public:
    CardDeck(int suits = 4, int ranks = 13);
    void swap(int a, int b);
    Card drawCard();
    void shuffle();
    void print();
};