#pragma once
/*
    Dao, Kenneth
    Jensen, Shuma

    Project: Blackjack
    9/22/2024
*/

#include <vector>
#include <algorithm>

#include "Card.h"


#ifndef DECK_H
#define DECK_H

using namespace std;

class Deck {
public:

    Deck();

    //functions
    Card deal_card(); // deals the card to the house and the player from the vector, takes the cards out of the vector 
    void reset();  // recreates the missing cards into the deck 
    int getDeckSize(); // returns the size of the deck (number of remaining cards)

private:

    vector<Card> Cards;
    

};


#endif 
