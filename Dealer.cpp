//
// Created by andy on 11/15/2018.
//

#include "Dealer.h"

Dealer::Dealer( std::vector <Player>* players ) : players(players), deck(Deck((int) players->size())) {
    dealRound(8);
    playTrick();

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
    pickTrump();
    showTrump();
}

const Card &Dealer::getTrump() const {
    return trump;
}

void Dealer::pickTrump() {
    if( !deck.empty() ){
        trump = deck.nextCard();
    }
}

void Dealer::showTrump() {
    std::cout << "Trump" << "\t:\t";
    if (trump.getFace()){
         std::cout << trump.getName() << '\n';
    }else{
        std::cout << "No Trump" << '\n';
    }
}

void Dealer::playTrick() {
    for( auto &p : *players){
        trick.push_back(p.playTrick(*this));
    }
}

const Card &Dealer::getTrickSuit() const {
    return trick.front();
}

