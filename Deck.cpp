//
// Created by andy on 11/15/2018.
//

#include "Deck.h"

Deck::Deck(int players) {

    // Max 6 players; Min 1 player;
    if (players > 6 || players < 1){
        throw std::invalid_argument("Invalid number of players; Valid : 1-6");
    }
    for (int f = ACE; f < players * 2; f++){
        for (int s = CLUBS; s <= SPADES; s++){
            deck.emplace_back((Face) f, (Suit) s);
        }
    }
}

void Deck::shuffle() {

    for (auto &c : deck) {
        std::swap(deck[rand() % deck.size()], c);
    }
}

Card Deck::nextCard() {
    Card temp = deck.back();
    deck.pop_back();
    return temp;
}