//
// Created by andy on 11/15/2018.
//

#include "Dealer.h"

Dealer::Dealer( std::vector <Player>* players ) : deck( (int) players->size() ), players(players) {
   dealRound(8);
}

void Dealer::dealCard(Player* p) {
   p->beDealt(deck.nextCard());
}


void Dealer::dealRound(int cards) {
    deck.shuffle();
    for( int i = 0; i < cards; i++) {
        for (auto &p : *players) {
            dealCard(&p);
        }
    }
}

