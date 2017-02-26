//
// Created by Adam on 2/26/2017.
//
/*
 * card_imp.cpp
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
#include "card.h"

using namespace std;

//Function Prototypes
//Default constructor to build a card if no value is passed/
Card::Card() {
    suit = spades;
    rank = 1;
}

//Card Constructor  to create a card from the values passed.
Card::Card(int r, Suit s) {
    rank = r;
    suit = s;
}

//create a string by concatenation of rank and suit
string Card::toString() const {
    string str1 = suitString();
    string str2 = rankString();
    return str2 + str1;
}

//get rank returns a rank from deck class
int Card::getRank() const {
    return rank;
}

//getSuit returns a suit from deck class
Card::Suit Card::getSuit() const {
    return suit;
}

//compares suit and rank of card and returns true or false
bool Card::operator==(const Card &rhs) const {
    return suit == rhs.suit || rank == rhs.rank;
}

//suitString creates a string variable from value passed by getSuit
string Card::suitString() const {
    Suit str_rcved;
    string suitStr;
    str_rcved = getSuit();

    if (str_rcved == spades) {
        suitStr = "s";
    } else if (str_rcved == hearts) {
        suitStr = "h";
    } else if (str_rcved == diamonds) {
        suitStr = "d";
    } else if (str_rcved == clubs) {
        suitStr = "c";
    } else {
        cout << "error has occurred in suitString.";
    }
    return suitStr;
}

//rank String creates a string variable from value passed by getRank
string Card::rankString() const {
    int str_rcved2;
    string rankStr = "";
    str_rcved2 = getRank();

    if (str_rcved2 == 1) {
        rankStr = "A";
    } else if (str_rcved2 == 2) {
        rankStr = "2";
    } else if (str_rcved2 == 3) {
        rankStr = "3";
    } else if (str_rcved2 == 4) {
        rankStr = "4";
    } else if (str_rcved2 == 5) {
        rankStr = "5";
    } else if (str_rcved2 == 6) {
        rankStr = "6";
    } else if (str_rcved2 == 7) {
        rankStr = "7";
    } else if (str_rcved2 == 8) {
        rankStr = "8";
    } else if (str_rcved2 == 9) {
        rankStr = "9";
    } else if (str_rcved2 == 10) {
        rankStr = "10";
    } else if (str_rcved2 == 11) {
        rankStr = "J";
    } else if (str_rcved2 == 12) {
        rankStr = "Q";
    } else if (str_rcved2 == 13) {
        rankStr = "K";
    } else {
        cout << "error has occurred in rankString.";
    }
    return rankStr;
}

