//
// Created by Adam on 2/26/2017.
//

#ifndef CRAZY_EIGHTS_CARD_H
#define CRAZY_EIGHTS_CARD_H

/*
 * card.h
 *
 *  Created on: Feb 2, 2015
 *      Author: Adam
 */

#include <iostream>
#include <string>

using namespace std;

class Card {
public:

    enum Suit {
        spades, hearts, diamonds, clubs
    };

    Card();                     // default: ace of spades

    Card(int, Suit);

    string toString() const;  // return string version: Ac 4h Js
    int getRank() const;  // return rank, 1..13
    Suit getSuit() const;  // return suit

    bool operator==(const Card &rhs) const;

private:

    int rank;
    Suit suit;

    string suitString() const;  // return "s", "h",...
    string rankString() const;  // return "A", "2", ..."Q"

};

#endif //CRAZY_EIGHTS_CARD_H
