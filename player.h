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

    const std::string &getName() const;

private:
    std::string name;
    std::vector <Card> hand;
    bool hasSuitOf(Card a);
    int tricksWon;
public:
    int getTricksWon() const;
    void winTrick();
    int getScore() const;
    void addScore(int points);
    void newRound();

private:
    int score;
};


#endif //WHIST_PLAYER_H
