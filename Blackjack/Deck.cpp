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

void Deck::shuffle(){
    random_device rd;
    mt19937 g(rd());    
    shuffle(Cards.begin(), Cards.end(), g); // <-- ? im getting an error for the first Card
}

Card Deck::deal_card(){
    if(!Cards.empty()){
        Card deal = Cards.back(); 
        Cards.pop_back(); 

        return deal; 
    }
}

int Deck::getDeckSize(){
    return Cards.size(); 
}
