/*
 * crazy_eights_driver.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Adam C. De Leon
 *      netID: acd21
 *      studentID: A00490677
 */
#include <iostream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

//***********************************************************
// dealHand: deals a specified number of cards from the deck
//           into a player's hand.
// d: the Deck of Dards
// p: the Player
// numCards: the number of cards to deal
//***********************************************************

void dealHand(Deck &d, Player &p, int numCards) {
    for (int i = 0; i < numCards; i++)
        p.addCard(d.dealCard());
}

int main() {
    int numCards = 7;    // size of a hand

    Player p1("Joe");    // player 1
    Player p2("Jane");   // player 2

    // create a deck of cards (shuffled).
    Deck d;

    // deal out cards to each player
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    //show hands of each player
    cout << p1.getName() << " has : " << p1.showHand() << endl;
    cout << p2.getName() << " has : " << p2.showHand() << endl;

    //create a card to set as the card being evaluated against.
    Card play_card;
    int r;            //int created for passing rank for evaluation
    Card::Suit s;    //Suit created for passing suit for evaluation
    play_card = d.dealCard();  //evaluation card is dealt
    cout << "the discard pile has a " << play_card.toString() << " " << endl;
    r = play_card.getRank();    //set r to evaluation cards rank
    s = play_card.getSuit();    //set s to evaluation cards suit

    //continue to play the game until deck is empty or a player has 0 cards.
    do {
        //player 1 plays until a card is removed from hand by a match.
        do {
            if (p1.hasCardWithRank(r, play_card)) {
                cout << "Joe plays a " << play_card.toString() << endl;
                p1.removeCardFromHand(play_card);
                cout << "the discard pile has a " << play_card.toString() << " "
                     << endl;

            } else if (p1.hasCardWithSuit(s, play_card)) {
                cout << "Joe plays a " << play_card.toString() << endl;
                p1.removeCardFromHand(play_card);

                cout << "the discard pile has a " << play_card.toString() << " "
                     << endl;

            } else {
                p1.addCard(d.dealCard());

            }
        } while (!p1.removeCardFromHand(play_card));

        //show player one's hand.
        cout << endl;
        cout << "Joe has " << p1.showHand() << endl;

        //if player 1 has no cards send message to console indicating win.
        if (p1.getHandSize() == 0) {
            cout << p1.getName() << " wins!" << endl;
            break;
        }

        //player 2 plays until a card is removed from hand by a match.
        do {
            if (p2.hasCardWithRank(r, play_card)) {
                cout << "Jane plays a  " << play_card.toString() << endl;
                p2.removeCardFromHand(play_card);
                cout << "the discard pile has a " << play_card.toString() << " "
                     << endl;
            } else if (p2.hasCardWithSuit(s, play_card)) {
                cout << "Jane plays a " << play_card.toString() << endl;
                p2.removeCardFromHand(play_card);
                cout << "the discard pile has a " << play_card.toString() << " "
                     << endl;
            } else {
                p2.addCard(d.dealCard());
            }
        } while (!p2.removeCardFromHand(play_card));

        //show player two's hand.
        cout << endl;
        cout << "Jane has " << p2.showHand() << endl;

        //if player 2 has no cards send message to console indicating win.
        if (p2.getHandSize() == 0) {
            cout << p2.getName() << " wins!" << endl;
            break;
        }
    } while (d.size() != 0 || p1.getHandSize() != 0 || p2.getHandSize() != 0);

    return 0;
}

