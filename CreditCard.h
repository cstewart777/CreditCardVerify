/**
 * @file Project01Stewart/CreditCard.h
 * The header file for CreditCard class
 * @author Collin Stewart
 * @date October 2021
 */
#ifndef PROJECT01STEWART_CREDITCARD_H
#define PROJECT01STEWART_CREDITCARD_H

#include <iostream>
using namespace std;
class CreditCard {

private:

    /** set the length of the array*/
    static const int SIZE = 16;
    int numArray[SIZE];

public:

    /**
     * Default constructor, sets the card array length to 16.
     */
    CreditCard();

    /**
     * Getter for cardNumber.
     * @param cardNum
     * @return card number.
     */
    bool cardNumber(string cardNum);

    /**
     * Getter for card length.
     * @param cardNum
     * @return card number length.
     */
    bool cardLength(string cardNum);

    /**
     * Getter for luhn algorithm
     * @return luhn algorithm on the card to test validity.
     */
    bool luhnAlg();

    /**
     * Getter for toString method
     * @return numArray into a string with dashes.
     */
    string toString();
};


#endif //PROJECT01STEWART_CREDITCARD_H
