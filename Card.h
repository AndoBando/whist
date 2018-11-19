//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_CARD_H
#define WHIST_CARD_H
#include <string>

enum Suit {CLUBS,DIAMONDS,HEARTS,SPADES,NOSUIT};
enum Face {ACE,KING,QUEEN,JACK,TEN,NINE,EIGHT,SEVEN,SIX,FIVE,FOUR,THREE,TWO,NOFACE};

class Card {

private:
    Face face;
    Suit suit;
    std::string name;
public:
    const std::string &getName() const;

public:
    Card(Face face, Suit suit);
    Card();

    const Face getFace() const;
    const Suit getSuit() const;
};


#endif //WHIST_CARD_H
