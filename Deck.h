//
// Created by andy on 11/15/2018.
//

#ifndef WHIST_DECK_H
#define WHIST_DECK_H
#include <vector>
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>


class Deck {
private:
    std::vector <Card> deck;
public:
    Deck(int players);
    void shuffle();
    Card nextCard();
};


#endif //WHIST_DECK_H
