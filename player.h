//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_PLAYER_H
#define WHIST_PLAYER_H
#include <vector>
#include "Card.h"
#include <iostream>
#include <string>

class Player {
public:
    Player(std::string);

    void beDealt(Card);
    void showHand();

private:
    std::string name;
    std::vector <Card> hand;
    bool sameSuit(Card a, Card b);
    bool betterFace(Card a, Card b);
};


#endif //WHIST_PLAYER_H
