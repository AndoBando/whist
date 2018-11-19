//
// Created by andy on 11/15/2018.
//

#include "Dealer.h"

Dealer::Dealer( std::vector <Player>* players ) : players(players), deck(Deck((int) players->size())) {
    secSep = "---------------------\n";
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

void Dealer::showTable() {
    std::cout << "Table" << "\t:\t";
    for(auto &c :trick){
        std::cout << c.getName() << ' ';
    }
    std::cout << '\n';
}

Player Dealer::playTrick() {
    Player winningPlayer = players->front();
    Card winningCard;
    for( auto &p : *players){
        showTrump();
        showTable();
        trick.push_back(p.playTrick(*this));
        if(!winningCard.betterFaceThan(trick.back()) && trick.back().sameSuit(trump)){
            winningCard = trick.back();
            winningPlayer = p;
        }else if(!winningCard.betterFaceThan(trick.back()) && trick.back().sameSuit(trick.front())){
            winningCard = trick.back();
            winningPlayer = p;
        }
        std::cout << secSep;
    }
    std::cout << winningPlayer.getName() << " won the trick with : " << winningCard.getName() << '\n';
    std::cout << secSep;

}


const Card &Dealer::getTrickSuit() const {
    if (!trick.empty()) {
        Card fCard = trick.front();
    }
    return fCard;
}

void Dealer::playRound(int roundSize) {
    for(auto &p : *players){
        p.newRound();
    }
    dealRound(roundSize);
    for(int i = 0; i < roundSize; i++) {
        trick.clear();
        fCard = Card();
        playTrick().winTrick();
    }
    std::cout << "test";
    for(auto &p : *players){
        std::cout << p.getName() << " won " << p.getTricksWon() << " tricks.\n";
    }
}

