//
// Created by andy on 11/15/2018.
//

#include "Player.h"

void Player::beDealt(Card c) {
    hand.push_back(c);
}

Player::Player(std::string name) : hand( std::vector <Card>() ), name(name) {}

bool Player::sameSuit(Card a, Card b) {
    return a.getSuit() == b.getSuit();
}
bool Player::betterFace(Card a, Card b){
    return a.getFace() > b.getFace();
}

void Player::showHand() {
    std::cout << name << "\t:\t";
    for(auto &c :hand){
        std::cout << c.getName() << ' ';
    }
    std::cout << '\n';
}