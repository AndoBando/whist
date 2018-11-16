//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_DEALER_H
#define WHIST_DEALER_H

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>

class Dealer{
public:
    Dealer(std::vector <Player>* players);
    void dealCard(Player* p);
    void dealRound(int cards);

private:
    Deck deck;
    std::vector <Player>* players;
    int playNum;
};


#endif //WHIST_DEALER_H
