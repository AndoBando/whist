//
// Created by andy on 11/15/2018.
//

#include "Dealer.h"

Dealer::Dealer( std::vector <Player>* players ) : players(players), deck(Deck((int) players->size())) {
    secSep = "---------------------\n";
    playerShift = 0;
}

void Dealer::dealCard(Player* p) {
   p->beDealt(deck.nextCard());
}


void Dealer::dealRound(int cards) {
    deck = Deck((int) players->size());
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

void Dealer::playTrick() {

    Player* winningPlayer = &players->front();
    Card winningCard;

    for( auto &p : *players){

        trick.push_back(p.playTrick(*this));

        if(!winningCard.betterFaceThan(trick.back()) && trick.back().sameSuit(trump)){
            winningCard = trick.back();
            winningPlayer = &p;
        }else if(!winningCard.betterFaceThan(trick.back()) && trick.back().sameSuit(trick.front())){
            winningCard = trick.back();
            winningPlayer = &p;
        }
        showTable();
    }

    std::cout << winningPlayer->getName() << " won the trick with : " << winningCard.getName() << '\n';
    winningPlayer->winTrick();

    int shift = (int) (winningPlayer - &players->front());
    playerShift = (playerShift - shift) % (int) players->size();
    std::rotate(players->begin(),players->begin()+shift,players->end());

    std::cout << secSep;

}


const Card &Dealer::getTrickSuit() const {
    if (!trick.empty()) {
        Card fCard = trick.front();
    }
    return fCard;
}

void Dealer::getWagers(int roundSize) {
    std::cout << secSep;
    std::cout << "Wagers" << "\n";
    std::cout << "Round Size" << "\t:\t" << roundSize << '\n';
    showTrump();
    std::cout << secSep;
    int sum = 0;
    for (auto &p : *players){

        p.showHand();
        std::cout << p.getName() << "\t:\t";
        int w;
        std::cin >> w;
        sum += w;
        p.setWager(w);
    }
    while(sum == roundSize){
        std::cout << "There cannot be the same number of tricks wagered as tricks available.\n";
        Player *p = &players->back();
        sum -= p->getWager();
        std::cout << p->getName() << "\t:\t";
        int w;
        std::cin >> w;
        sum += w;
        p->setWager(w);
    }


    std::cout << secSep;
}


void Dealer::playRound(int roundSize) {

    std::rotate(players->begin(),players->begin()+playerShift,players->end());
    for(auto &p : *players){
        p.newRound();
    }
    dealRound(roundSize);

    getWagers(roundSize);
    for(int i = 0; i < roundSize; i++) {
        trick.clear();
        fCard = Card();
        playTrick();
    }
    for(auto &p : *players){
        std::cout << p.getName() << " won " << p.getTricksWon() << " tricks and wagered " << p.getWager() << " tricks.\n";
    }
    std::cout << secSep;
    for(auto &p: *players){
        if (p.getWager() == p.getTricksWon()) {
            int scoreDif = 5 + p.getWager();
            p.addScore(scoreDif);
            std::cout << p.getName() << "\t:" << "(+" << scoreDif << ") " << p.getScore() << '\n';
        }else{
            int scoreDif = abs(p.getWager() - p.getTricksWon());
            p.addScore(-scoreDif);
            std::cout << p.getName() << "\t:" << "(-" << scoreDif<< ") " << p.getScore() << "\n";
        }
    }
    playerShift++;
}

Player Dealer::getWinner() {
    Player winner = players->front();
    for(auto &p : *players){
        if(p.getScore() >= winner.getScore() ){
            winner = p;
        }
    }
    return winner;
}


