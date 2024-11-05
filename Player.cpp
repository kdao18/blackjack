/*
    Dao, Kenneth
    Jensen, Shuma

    Project: Blackjack
    9/22/2024
*/

#include <string>
#include <sstream>

#include "Player.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

Player::Player() {
    vector<Card> Hand;
    
    aceCount = 0;
}

void Player::hit(const Card& card) {
    Hand.push_back(card);
}

void Player::stand() {
    bool isStanding = true;
}

int Player::getHandValue()  {
    int total_score = 0;
    for(int i = 0; i < Hand.size(); i++) {
        total_score = total_score + static_cast<int>(Hand[i].getRank());  //<-- I changed this from initial_hand(what we had inside the parameters to Hand[i])
        if (static_cast<int>(Hand[i].getRank()) == 11)
        {
            aceCount++;
        }
    }
    
    return total_score;
}

bool Player::Busted(){ //erased the parameters also now returns true/false
    int score = getHandValue(); //erased the parameters

    if (score > 21) {
        return true; 
    }
    else {
        return false; 
    }
}

void Player::clearHand() {
    Hand.clear();
    total_score = 0;
    aceCount = 0;

    bool isStanding = false;
}

string Player::showHand() const {
    std::ostringstream oss;
    for (const auto& card : Hand) {
        oss << card.toString() << "\n";
    }
    oss << "Total value: " << total_score;
    return oss.str();
}

void Player::adjustForAces() {
    while (total_score > 21 && aceCount > 0) {
        total_score -= 10;  // Count the Ace as 1 instead of 11
        aceCount--;
    }
}
