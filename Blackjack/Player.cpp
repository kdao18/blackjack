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

Player::Player(){
    vector<Card> Hand; 
    totalScore = 0; 
    aceCount = 0; 
}

void Player::hit(const Card& card){
    Hand.push_back(card); 
}

void Player::stand(){
    bool isStanding = true; 
}

int Player::getHandValue() const {
    for(int i = 0; i < Hand.size(); i++){
        int totalScore = Hand.getRank();  //<-- i want to be able to use getRank form Card.h so that I can see the value of each card
    }

    return totalScore; 
}

bool Player::isBusted() const{
    int score = getHandValue();

    if(score > 21){
        return true; 
    }else{
        return false; 
    }
}

void Player::clearHand(){
    Hand.clear(); 
    totalScore = 0; 
    aceCount = 0; 

    bool isStanding = false; 
}

string Player::showHand() const{
    std::ostringstream oss;
    for (const auto& card : Hand) {
        oss << card.toString() << "\n";
    }
    oss << "Total value: " << totalScore;
    return oss.str();
}

void Player::adjustForAces(){
    while (totalScore > 21 && aceCount > 0) {
        totalScore -= 10;  // Count the Ace as 1 instead of 11
        aceCount--;
    }
}
