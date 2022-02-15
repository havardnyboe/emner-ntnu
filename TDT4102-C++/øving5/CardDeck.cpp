#include "CardDeck.hpp"

CardDeck::CardDeck(int suits, int ranks) {
    for (int i = 0; i < suits; i++) {
        for (int j = 1; j <= ranks; j++) {
            cards.push_back(Card(static_cast<Suit>(i), static_cast<Rank>(j)));
        }
    }
}

void CardDeck::swap(int indexA, int indexB) {
    Card tmp{cards.at(indexA)};
    cards.at(indexA) = cards.at(indexB);
    cards.at(indexB) = tmp;
};

Card CardDeck::drawCard() {
    Card card = cards.at(cards.size() - 1);
    cards.pop_back();
    return card;
};

void CardDeck::shuffle() {
    for (int i = 0; i < cards.size(); i++) {
        swap(i, rand() % cards.size());
    }
};

void CardDeck::print() {
    for (Card card : cards) {
        std::cout << card.toString() << std::endl;
    }
};