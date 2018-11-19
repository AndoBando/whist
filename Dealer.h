//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_DEALER_H
#define WHIST_DEALER_H

#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>

class Player;
class Dealer{
public:
    explicit Dealer(std::vector <Player>* players);

    void dealCard(Player* p);
    void dealRound(int cards);
    void pickTrump(); // 2016 lol
    void showTrump();
    void playTrick();
    void showTrick();

    const Card &getTrickSuit() const;
    const Card &getTrump() const;

private:
    Deck deck;
    std::vector <Player>* players;
    Card trump;
    Card fCard;
    std::vector <Card> trick;
};


#endif //WHIST_DEALER_H
