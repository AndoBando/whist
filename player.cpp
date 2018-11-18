//
// Created by andy on 11/15/2018.
//

#include "Player.h"

void Player::beDealt(Card c) {
    hand.push_back(c);
}

Player::Player(std::string name) : hand( std::vector <Card>() ), name(name) {}

void Player::showHand() {
    std::cout << name << "\t:\t";
    for(auto &c :hand){
        std::cout << c.getName() << ' ';
    }
    std::cout << '\n';
}

bool Player::sameSuit(Card a, Card b) {
    return a.getSuit() == b.getSuit();
}
bool Player::betterFace(Card a, Card b){
    return a.getFace() > b.getFace();
}
bool Player::hasSuitOf(Card a) {
    for( auto &c : hand ){
        std::cout << sameSuit(a,c);
        if( sameSuit(c,a)) { return true;}
    }
    return false;
}

Card Player::playTrick(Dealer d) {
    showHand();

    int a;
    bool cardChosen = false;
    while(!cardChosen){
        std::cout << name << "\t:\t";
        std::cin >> a;
        if( a > hand.size() || a < 0){
            std::cout << "Bad Index" << '\n';
            continue;
        }
        Card c = hand[a];
        if( !sameSuit(c,d.getTrump()) && hasSuitOf(d.getTrump()) ){
            std::cout << "If you have a trump, you must play it" << '\n';
            continue;
        }
        if( !sameSuit(c,d.getTrickSuit()) && hasSuitOf(d.getTrickSuit()) ){
            std::cout << "If you can, you must follow suit" << '\n';
            continue;
        }
        hand.erase( hand.begin() + a );
        return c;
    }

}

