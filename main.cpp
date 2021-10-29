/**
 * @file Project01Stewart/main.cpp
 * Project to validate credit card number
 * @author Collin Stewart
 * @date October 2021
 */

#include <iostream>
#include "CreditCard.h"
using namespace std;

int main() {

    /**Initialized variables.*/
    string creditNum = " ";   //Variable for user input.
    bool runLoop = true;      //Loop will continue when true.

    /**New instance of credit card class*/
    CreditCard myCreditCard;

    while(runLoop) {

        /**Prompt user to enter in credit card number and read in input.*/
        std::cout << "Enter a 16 digit credit card number on a single line or type (exit) to leave the program.\n" << std::endl;
        getline(cin, creditNum);

        /**If the card length and card number are valid it will perform the luhn algorithm.*/
        if (myCreditCard.cardLength(creditNum) && myCreditCard.cardNumber(creditNum)){
            /** If the length and number are true it will perform the luhn algorithm to determine validity.*/
            if(myCreditCard.luhnAlg()){
                cout << myCreditCard.toString() + " is a valid credit card!\n";
            }
            else{
                cout << myCreditCard.toString() + " is an invalid credit card.\n";
            }
        }
        /**When user types (exit) it will exit the program.*/
        else if(creditNum == "exit"){
            runLoop = false;
        }
        /**If the card is not 16 digits or has any other characters that are not permitted*/
        else if(!myCreditCard.cardLength(creditNum) || !myCreditCard.cardNumber(creditNum)){
            cout << "Please enter a valid 16 digit number \n";
        }
    }
}
