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
    int getHandValue() const;

    // Check if the player has busted (hand value > 21)
    bool isBusted() const;

    // Clear the player's hand (for starting a new round)
    void clearHand();

    // Get a string representation of the player's hand
    std::string showHand() const;

private:
    vector<Card> Hand;

    int totalScore;
    int aceCount;

    void adjustForAces();
};


#endif
