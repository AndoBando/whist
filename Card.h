//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_CARD_H
#define WHIST_CARD_H
#include <string>

enum Suit {CLUBS,DIAMONDS,HEARTS,SPADES};
enum Face {ACE,KING,QUEEN,JACK,TEN};

class Card {

private:
    const Face face;
    const Suit suit;
    const std::string name;

public:
    Card(Face face, Suit suit);

    const Face getFace() const;
    const Suit getSuit() const;
    const std::string &getName() const;
};


#endif //WHIST_CARD_H
