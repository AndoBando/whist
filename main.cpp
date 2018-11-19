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
    
    return 0;
}