/*
    Dao, Kenneth
    Jensen, Shuma

    Project: Blackjack
    9/22/2024
*/

#include <iostream>

#include "Card.h"
using namespace std;

Card::Card(Rank r, Suit s)
{
    rank = r;
    suit = s;
    if (r >= Rank::Ace and r <= Rank::Ten)
    {
        value = static_cast<int>(r);
    }
    else if (r == Rank::Jack or r == Rank::Queen or r == Rank::King)
    {
        value = 10;
    }
    else
    {
        value = 11;
    }
}

Card::Suit Card::getSuit() const
{
    return suit;
}

Card::Rank Card::getRank() const
{
    return rank;
}

int Card::getValue() const
{
    return value;
}

string Card::toString() const
{
    string rankStr;

    switch (rank) 
    {
        case Rank::Ace:   rankStr = "Ace"; break;
        case Rank::Two:   rankStr = "Two"; break;
        case Rank::Three: rankStr = "Three"; break;
        case Rank::Four:  rankStr = "Four"; break;
        case Rank::Five:  rankStr = "Five"; break;
        case Rank::Six:   rankStr = "Six"; break;
        case Rank::Seven: rankStr = "Seven"; break;
        case Rank::Eight: rankStr = "Eight"; break;
        case Rank::Nine:  rankStr = "Nine"; break;
        case Rank::Ten:   rankStr = "Ten"; break;
        case Rank::Jack:  rankStr = "Jack"; break;
        case Rank::Queen: rankStr = "Queen"; break;
        case Rank::King:  rankStr = "King"; break;
    }

    string suitStr;
    switch (suit) 
    {
        case Suit::Hearts:   suitStr = "Hearts"; break;
        case Suit::Diamonds: suitStr = "Diamonds"; break;
        case Suit::Clubs:    suitStr = "Clubs"; break;
        case Suit::Spades:   suitStr = "Spades"; break;
    }

    return rankStr + " of " + suitStr;
}
