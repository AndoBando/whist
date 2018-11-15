//
// Created by andy on 11/15/2018.
//

#include "Card.h"
#include <string>

Card::Card(Face face, Suit suit) : face(face), suit(suit) {
    
}

const Face Card::getFace() const {
    return face;
}

const Suit Card::getSuit() const {
    return suit;
}

const std::string &Card::getName() const {
    return name;
}
