//
// Created by Adam on 2/26/2017.
//

#ifndef CRAZY_EIGHTS_DECK_H
#define CRAZY_EIGHTS_DECK_H

/*
 * deck.h
 *
 *  Created on: Feb 2, 2015
 *      Author: Adam
 */

#include "card.h"

class Deck {
    static const int SIZE = 52;

public:

    Deck();            // pristine, shuffled deck (cards in random order)

    Card dealCard();   // get a card, after 52 are dealt, fail

    int size() const;  // # cards left in the deck

private:

    Card cards[SIZE];  // ARRAY
    int index;         // current card to deal
};

#endif //CRAZY_EIGHTS_DECK_H
