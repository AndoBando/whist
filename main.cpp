#include <iostream>
#include<string>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"


int main() {

    std::string names[3] = {"Alice","Bob ","Charlie"};
    std::vector <Player> players;

    for(auto &n: names){
        players.push_back( Player(n) );
    }

    Dealer d = Dealer(&players);

    for(auto &n : names){
        d.playRound(1);
    }
    for(int i = 2; i < 8; i++){
        d.playRound(i);
    }
    for(auto &n : names){
        d.playRound(8);
    }
    for(int i = 7; i > 1; i++){
        d.playRound(i);
    }
    for(auto &n : names){
        d.playRound(1);
    }
    std::cout << "GAME OVER\n";
    std::cout << d.getWinner().getName() << "wins with a score of" << d.getWinner().getScore() << "!";

    return 0;
}