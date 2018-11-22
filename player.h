//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_PLAYER_H
#define WHIST_PLAYER_H
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Card.h"
#include "Dealer.h"

class Dealer;
class Player {
public:
    Player(std::string);
    Player();
    void beDealt(Card);
    void showHand();
    void winTrick();
    void addScore(int points);
    void newRound();
    const std::string &getName() const;
    Card playTrick(Dealer d);
    int getTricksWon() const;
    int getScore() const;

private:
    std::string name;
    std::vector <Card> hand;
    bool hasSuitOf(Card a);
    int tricksWon;
    int wager;
public:
    int getWager() const;

    void setWager(int wager);


private:
    int score;
};


#endif //WHIST_PLAYER_H
