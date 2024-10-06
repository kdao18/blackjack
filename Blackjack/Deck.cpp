/*
    Dao, Kenneth
    Jensen, Shuma

    Project: Blackjack
    9/22/2024
*/
#include <random>
#include <algorithm>
#include <vector>

#include "Deck.h"
#include "Card.h"


using namespace std;

//constructor of the deck of cards
Deck::Deck() {
    for (int suit_value = 1; suit_value <= 4; ++suit_value) {
        Card::Suit suit = static_cast<Card::Suit>(suit_value);  // Cast int to Suit enum
        for (int rank_value = 1; rank_value <= 13; ++rank_value) {
            Card::Rank rank = static_cast<Card::Rank>(rank_value);  // Cast int to Rank enum
            Cards.push_back(Card(rank, suit));
        }
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(Cards.begin(), Cards.end(), generator);
}

// recreating the deck of cards
void Deck::reset() {
    Cards.clear();
    
    for (int suit_value = 1; suit_value <= 4; ++suit_value) {
        Card::Suit suit = static_cast<Card::Suit>(suit_value);  // Cast int to Suit enum
        for (int rank_value = 1; rank_value <= 13; ++rank_value) {
            Card::Rank rank = static_cast<Card::Rank>(rank_value);  // Cast int to Rank enum
            Cards.push_back(Card(rank, suit));
        }
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(Cards.begin(), Cards.end(), generator);
    
}

Card Deck::deal_card() {
    if (!Cards.empty()) {
        Card deal = Cards.back();
        Cards.pop_back();

        return deal;
    }
}

int Deck::getDeckSize() {
    return Cards.size();
}
