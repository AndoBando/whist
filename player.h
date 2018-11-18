//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_PLAYER_H
#define WHIST_PLAYER_H
#include <vector>
#include <iostream>
#include <string>
#include "Card.h"
#include "Dealer.h"

class Dealer;
class Player {
public:
    Player(std::string);
    void beDealt(Card);
    void showHand();
    Card playTrick(Dealer d);

private:
    std::string name;
    std::vector <Card> hand;
    bool sameSuit(Card a, Card b);
    bool betterFace(Card a, Card b);
    bool hasSuitOf(Card a);
};


#endif //WHIST_PLAYER_H
