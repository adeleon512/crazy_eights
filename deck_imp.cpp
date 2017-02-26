//
// Created by Adam on 2/26/2017.
//
/*
 * deck_imp.cpp
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
#include <cassert>
#include "card.h"
#include "deck.h"

using namespace std;

//Function Prototypes
/*****************************************************************************
 * Deck constructor that first builds a deck in sequential order. Each value
 * for rank and suit are created one by one then stored in a card object that
 * is created afterwards. This card object then passes it value into the
 * array of cards. This process is run 52 times to generate an entire deck.
 * After the deck is created in its entirety, the array of cards is shuffled.
 */
Deck::Deck() {
    index = 0;
    Card::Suit suitType;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 14; j++) {
            switch (i) {
                case 0:
                    suitType = Card::spades;
                    break;

                case 1:
                    suitType = Card::hearts;
                    break;

                case 2:
                    suitType = Card::diamonds;
                    break;

                case 3:
                    suitType = Card::clubs;
                    break;
            }
            Card c_obj(j, suitType);
            cards[index] = c_obj;
            index++;
        }
    }

    //This code shuffles the deck randomly.
    int x = 0;
    int y;
    Card temp;
    srand(time(0));
    while (x < SIZE) {
        y = rand() % (x + 1);
        temp = cards[x];
        cards[x] = cards[y];
        cards[y] = temp;
        x++;
    }
}

/*****************************************************************************
 * dealCard - This function first checks to see if the deck is empty by use of
 * assert. If the assert is true the program terminates and a message is
 * printed indicating the deck is empty and the game has resulted in a draw.
 * If assert is not true a Card variable is created to represent the card
 * being dealt from the deck. The index of the deck is then decremented by
 * one.
 */
Card Deck::dealCard() {
    assert(index != 0 && "The deck is empty. Game ends in a draw.");
    Card top;
    if (index > 0) {
        top = cards[index - 1];
        index--;
    }
    return top;
}

/*****************************************************************************
 * size - This function creates an integer variable and assigns it the value
 * of index. That value is then returned as an integer.
 * A message is sent to the console to indicate the size of deck.
 */
int Deck::size() const {
    int crnt_size;
    crnt_size = index;
    cout << "deck_size " << crnt_size << endl;
    return crnt_size;
}

