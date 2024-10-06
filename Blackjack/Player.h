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
    int getHandValue(const Card& initial_Hand);

    // Check if the player has busted (hand value > 21)
    void Busted(const Card& initial_Hand);

    // Clear the player's hand (for starting a new round)
    void clearHand();

    // Get a string representation of the player's hand
    std::string showHand() const;

private:
    vector<Card> Hand;

    int total_score = 0;
    int aceCount;

    bool isBusted = false;

    void adjustForAces();
};


#endif
