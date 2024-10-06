/*
    Dao, Kenneth
    Jensen, Shuma

    Project: Blackjack
    9/22/2024
*/

#include <string>
#include <sstream>

#include "player.h"
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

int Player::getHandValue(const Card& initial_Hand)  {
    int total_score = 0;
    for(int i = 0; i < Hand.size(); i++) {
        total_score = total_score + static_cast<int>(initial_Hand.getRank());  //<-- i want to be able to use getRank form Card.h so that I can see the value of each 
        if (static_cast<int>(initial_Hand.getRank()) == 11)
        {
            aceCount++;
        }
    }
    
    return total_score;
}

void Player::Busted(const Card& initial_Hand){
    int score = getHandValue(initial_Hand);

    if (score > 21) {
        isBusted = true;
    }
    else {
        isBusted = false;
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
