#include "Card.hpp"

string suitToString(Suit suit) {
    switch (suit) {
    case Suit::clubs:
        return "Clubs";
    case Suit::diamonds:
        return "Diamonds";
    case Suit::hearts:
        return "Hearts";
    case Suit::spades:
        return "Spades";
    }
}
string rankToString(Rank rank) {
    switch (rank) {
    case Rank::two:
        return "Two";
        break;
    case Rank::three:
        return "Three";
        break;
    case Rank::four:
        return "Four";
        break;
    case Rank::five:
        return "Five";
        break;
    case Rank::six:
        return "Six";
        break;
    case Rank::seven:
        return "Seven";
        break;
    case Rank::eight:
        return "Eight";
        break;
    case Rank::nine:
        return "Nine";
        break;
    case Rank::ten:
        return "Ten";
        break;
    case Rank::jack:
        return "Jack";
        break;
    case Rank::queen:
        return "Queen";
        break;
    case Rank::king:
        return "King";
        break;
    case Rank::ace:
        return "Ace";
        break;
    }
}
