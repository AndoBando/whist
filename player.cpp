//
// Created by andy on 11/15/2018.
//

#include "Player.h"

void Player::beDealt(Card c) {
    hand.push_back(c);
}


Player::Player() : hand( std::vector <Card>() ), name("") {
    score  = 0;
    tricksWon = 0;
}

Player::Player(std::string name){
    score = 0;
    tricksWon = 0;
    this->name = name;
}

void Player::showHand() {
    std::cout << name << "\t:\t";
    for(auto &c :hand){
        std::cout << c.getName() << ' ';
    }
    std::cout << '\n';
}


bool Player::hasSuitOf(Card a) {
    for( auto &c : hand ){
        if(c.sameSuit(a)) { return true;}
    }
    return false;
}

Card Player::playTrick(Dealer d) {
    showHand();
    int a;
    while(true){
        std::cout << name << "\t:\t";
        std::cin >> a;
        if( a >= hand.size() || a < 0){
            std::cout << "Bad Index" << '\n';
            continue;
        }
        Card c = hand[a];
        if( !c.sameSuit(d.getTrump()) && hasSuitOf(d.getTrump()) ){
            std::cout << "If you have a trump, you must play it" << '\n';
            continue;
        }
        if( !c.sameSuit(d.getTrickSuit()) && hasSuitOf(d.getTrickSuit()) ){
            std::cout << "If you can, you must follow suit" << '\n';
            continue;
        }
        hand.erase( hand.begin() + a );
        return c;
    }

}

const std::string &Player::getName() const {
    return name;
}

int Player::getTricksWon() const {
    return tricksWon;
}

void Player::winTrick() {
    Player::tricksWon++;

}
void Player::newRound() {
    Player::tricksWon = 0;
}

int Player::getScore() const {
    return score;
}

void Player::addScore(int points) {
    Player::score += points;
}

void Player::setWager(int wager) {
    Player::wager = wager;
}

int Player::getWager() const {
    return wager;
}


