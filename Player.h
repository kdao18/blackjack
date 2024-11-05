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
#include "Deck.h"

#ifndef Player_H
#define Player_H

class Player
{
public:
    Player();

    // Add a card to the player's hand
    void hit(const Card& card);

    void stand();

    // Get the total value of the player's hand
    int getHandValue(); // --> I made this mave no parameters

    // Check if the player has busted (hand value > 21)
    bool Busted(); // --> I made this have no parameters, I also changed this from a void function to a boolean function so that it can return a true or false. 

    // Clear the player's hand (for starting a new round)
    void clearHand();

    // Get a string representation of the player's hand
    std::string showHand() const;

    void adjustForAces(); //I moved adjustforaces into public so that I can call it in main 

private:
    vector<Card> Hand;

    int total_score = 0;
    int aceCount;



};


#endif
