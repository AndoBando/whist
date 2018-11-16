#include <iostream>
#include<string>
#include "Card.h"
#include "Deck.h"
int main() {

    Deck d = Deck(4);
    d.shuffle();
    return 0;
}