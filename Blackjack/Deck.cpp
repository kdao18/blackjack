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
Deck::Deck(){
    reset(); 
}

// recreating the deck of cards
void Deck::reset(){
    Cards.clear(); 

    const char Suits[] {'H', 'D', 'S', 'C'}; 
    for (int Rank = 2; Rank <= 14; Rank++){
        for(char Suit : Suits){
            Cards.push_back(Card(Rank, Suit)); // <-- ? im getting an error for the second Card
        }
    }

    shuffle(); 
}

void shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(Cards.begin(), Cards.end(), g); // <-- ? im getting an error for the first Card
}

