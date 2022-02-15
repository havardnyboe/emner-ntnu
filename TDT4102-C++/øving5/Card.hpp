#pragma once
#include <std_lib_facilities.h>

enum class Suit {
    clubs = 0,
    diamonds = 1,
    hearts = 2,
    spades = 3
};

enum class Rank {
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 11,
    queen = 12,
    king = 13,
    ace = 1
};

string suitToString(Suit suit);
string rankToString(Rank rank);

class Card {
  private:
    Suit s;
    Rank r;

  public:
    Card(Suit suit, Rank rank) {
        r = rank;
        s = suit;
    };
    Suit getSuit() { return s; };
    Rank getRank() { return r; };
    string toString() {
        return rankToString(r) + " of " + suitToString(s);
    };
};
