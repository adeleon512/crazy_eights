//
// Created by Adam on 2/26/2017.
//
/*
 * player_imp.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Adam C. De Leon
 *      netID: acd21
 *      student ID: A00490677
 */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

//Function prototypes
/*****************************************************************************
 * Player - Default constructor to generate a name if no names are passed
 * from main.
 */
Player::Player() {
    name = "Ted";
}

/*****************************************************************************
 * showHand - This function creates a string variable and then traverses the
 * players hand. The hand size is determined by passing the function
 * getHandSize. While the hand is being traversed the string variable is being
 * concatenated with any value that follows to generate a long single string
 * that which is returned by the function to represents the players hand.
 */
string Player::showHand() const {
    string hndStr = "";
    for (int i = 0; i < getHandSize(); i++) {
        hndStr += hand[i].toString() + ", ";
    }
    return hndStr;
}

/*****************************************************************************
 * getHandSize - This function creates an integer value and assign the value
 * of the hand size to it. This is done by using the .size() function
 * available with vectors. The value of hndSize is then returned as an
 * integer.
 */
int Player::getHandSize() const {
    int hndSize;
    hndSize = hand.size();
    return hndSize;
}

/*****************************************************************************
 * addCard - This function receives a card object from main and uses the
 * push_back() function available to vectors to add the value of the card
 * being passed from main to the end of the hand vector. Nothing is returned
 * becuase it is a void function.
 */
void Player::addCard(Card c) {
    hand.push_back(c);
}

/*****************************************************************************
 * removeCardFromHand - This function receives a card from main and removes
 * that card from the hand vector. This function is called based on conditions
 * within main using the hasCardWithRank and hasCardWithSuit functions. The
 * function returns true or false based up the previous conditions
 */
bool Player::removeCardFromHand(Card c) {
    for (int i = 0; i < getHandSize(); i++) {
        if (hand[i] == c) {
            hand.erase(hand.begin() + i);
            return true;
        }
    }
    return false;
}

/*****************************************************************************
 * hasCardWithRank - This function checks to see if the card being passed by
 * main has an 8 or the same rank as any of the cards in the players hand. If
 * this condition is true it returns true, else it returns false.
 */
bool Player::hasCardWithRank(int r, Card &c1) {
    for (int i = 0; i < getHandSize(); i++) {
        if (r == hand[i].getRank()) {
            c1 = hand[i];
            return true;
        } else if (8 == hand[i].getRank()) {
            c1 = hand[i];
            return true;
        }
    }
    return false;
}

/*****************************************************************************
 * hasCardWithSuit - This function checks to see if the card being passed by
 * main has the same suit as any of the cards in the players hand. If
 * this condition is true it returns true, else it returns false.
 */
bool Player::hasCardWithSuit(Card::Suit s, Card &c1) {
    for (int i = 0; i < getHandSize(); i++) {
        if (s == hand[i].getSuit()) {
            c1 = hand[i];
            return true;
        }
    }
    return false;
}

