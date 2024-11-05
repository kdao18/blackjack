/*
    Dao, Kenneth
    Jensen, Shuma

    Project: Blackjack
    9/22/2024
*/

#include <string>
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace std; 

void winner(Player& player, Player& dealer){
    int player_score = player.getHandValue(); 
    int dealer_score = dealer.getHandValue(); 

    if(player.Busted()){
        std::cout << "You busted! Dealer wins!" << endl;
    }else if(dealer.Busted()){
        std::cout << "Dealer busted! You win!" << endl;
    }else if(player_score > dealer_score){
        std::cout << "You win!" << endl; 
    }else if(dealer_score > player_score){
        std::cout << "Dealer wins!" << endl; 
    }else if(dealer_score == player_score){
        std::cout << "You tie!" << endl; 
    }
}

int main() {
    std::cout << "Welcome to Blackjack!\n";
    // main loop is while(!isBusted)
    // in main loop, when isBusted is true call adjust for aces
    // create while loop for the adjust aces for when isbusted is true


    bool isBusted = false;
    bool isStanding = false; 

    while(!isBusted){
        //create deck
        Deck deck; 

        //create the two players 
        Player player; 
        Player dealer; 

        //deal the initial cars, two to the player and one to the dealer
        player.hit(deck.deal_card()); 
        player.hit(deck.deal_card()); 
        dealer.hit(deck.deal_card()); 

        //player and dealer shows their hand
        player.showHand(); 
        dealer.showHand(); 

        //Players turn to hit or stand to reach ideal score
        while(!isStanding){
            //ask the player if he would like to hit or stand
            std::cout << "would you like to hit(1) or stand(2)" << endl; 
            int player_choice; 
            std::cin >> player_choice;  

            //hits and gains a new card
            if(player_choice == 1){
                player.hit(deck.deal_card()); 
                player.showHand(); 
                if(player.Busted()){
                    player.adjustForAces(); 
                }
            //stands and his turn is over
            }else if(player_choice == 2){
                isStanding = true;  
            }

        }

        //Dealers turn to draw cards until he gets 17 points or higher
        if(!player.Busted()){
            //only has one card showing so he will get the second card that was hidden
            dealer.hit(deck.deal_card()); 
            //shows the values of his two cards
            dealer.showHand(); 

            if(dealer.getHandValue() < 17){
                dealer.hit(deck.deal_card()); 
            }else if(dealer.getHandValue() >= 17){
                dealer.stand();
            }

            //adjust for aces
            if(dealer.Busted()){
                dealer.adjustForAces(); 
            }

        }

        //determine the winner 
        winner(player, dealer); 

        //ask if player would like to player again 
        string playAgain; 
        std::cout << "Do you want to player again? (y/n)" << endl; 
        std::cin >> playAgain; 

        if(playAgain == "y" || "Y"){
            isBusted = false; 
            if(deck.getDeckSize() <= 20){
                deck.reset(); 
            }
        }

    }

    return 0;
}
