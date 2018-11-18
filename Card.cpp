//
// Created by andy on 11/15/2018.
//

#include "Card.h"
#include <string>
#include <iostream>

Card::Card(Face face, Suit suit) : face(face), suit(suit) {
    name = "";
    switch (face) {
        case ACE:   name += 'A'; break;
        case KING:  name += 'K'; break;
        case QUEEN: name += 'Q'; break;
        case JACK:  name += 'J'; break;
        case TEN:   name += 'T'; break;
        case NINE:  name += '9'; break;
        case EIGHT: name += '8'; break;
        case SEVEN: name += '7'; break;
        case SIX:   name += '6'; break;
        case FIVE:  name += '5'; break;
        case FOUR:  name += '4'; break;
        case THREE: name += '3'; break;
        case TWO:   name += '2'; break;
    }
    switch (suit) {
        case CLUBS:    name += 'C'; break;
        case DIAMONDS: name += 'D'; break;
        case HEARTS:   name += 'H'; break;
        case SPADES:   name += 'S'; break;
    }
}
Card::Card(){}
const Face Card::getFace() const {
    return face;
}

const Suit Card::getSuit() const {
    return suit;
}

const std::string &Card::getName() const {
    return name;
}
