#pragma once
/*
    Dao, Kenneth
    Jensen, Shuma

    Project: Blackjack
    9/22/2024
*/
#ifndef CARD_H
#define CARD_H

using namespace std;

class Card
{
    // Define an enumeration for card suits
    enum class Suit { Hearts, Diamonds, Clubs, Spades };

    // Define an enumeration for card ranks
    enum class Rank { Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack, Queen, King };
public:
    
    Card(Rank r, Suit s);

    Suit getSuit() const;
    Rank getRank() const;
    int getValue() const;

    string toString() const;

    ~Card() {}
    
private:
    Rank rank;
    Suit suit;
    int value;

};
#endif 
