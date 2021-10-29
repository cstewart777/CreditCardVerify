/**
 * @file Project01Stewart/CreditCard.cpp
 * CPP file for CreditCard class
 * @author Collin Stewart
 * @date October 2021
 */

#include "CreditCard.h"

/** Inherits from credit card header file*/
CreditCard::CreditCard()= default;

/**Checks card number and returns the parameter cardNum*/
bool CreditCard::cardNumber(string cardNum){

    /** Initialized variables*/
    int sizeArray = cardNum.length();
    int i = 0;

    /** While loop to run when i is less than the size of the card entered
     * also removes 0's, spaces, and dashes.*/
    while(i<sizeArray){
        /** If the array index is a digit*/
        if(isdigit(cardNum[i])){
            numArray[i] = cardNum[i] - '0';
            i++;
        }
        /** If the array index is a space or a - then it will remove that index from the array*/
        else if(cardNum.compare(" ") || cardNum.compare("-")){
            cardNum.erase(i, 1);
            sizeArray--;
        }
        /** If its neither then it will break the while loop*/
        else{
            break;
        }
    }
  return true;
}

/** This function removes unnecessary characters and checks to see if the card array length is 16*/
bool CreditCard::cardLength(string cardNum){

    /** Initialized variables*/
    int sizeArray = cardNum.length();
    int i = 0;

    /** While loop to run when i is less than the size of the card entered
     * also removes 0's, spaces, and dashes.*/
    while(i<sizeArray) {
        /**If the array index is a digit*/
        if (isdigit(cardNum[i])) {
            numArray[i] = cardNum[i] - '0';
            i++;
        /** If array index is a space or a dash*/
        } else if (cardNum.compare(" ") || cardNum.compare("-")) {
            cardNum.erase(i, 1);
            sizeArray--;
        }
        /** When array index is neither it will break while loop*/
        else{
            break;
        }
    }
    /** If sizeArray is 16 then the function will return true*/
    if (sizeArray == 16){
        return true;
    }
    else{
        return false;
    }
}
/**Function to perform luhn's algorithm on card number to test validity*/
bool CreditCard::luhnAlg() {

    /**Initialized variables*/
    int evenSum = 0;
    int oddSum = 0;
    int sum;

    /**For loop to perform the algorithm*/
    for (int i = SIZE - 1; i>=0; i--){
        /**Variables for loop*/
        int numCard;
        int num = numArray[i];

        /**Multiplies the index by two*/
        if(i % 2 == 0){
            numCard = num * 2;
            /**If this index is greater than 9*/
            if (numCard>9){
                numCard = numCard - 9;
            }
            /**Adds numCard to evenSum to be used later*/
            evenSum += numCard;
        }
        /**When index isn't needed to check algorithm*/
        else{
            numCard = num;
            oddSum += numCard;
        }
    }
    /**Adds both numbers together into sum*/
    sum = oddSum + evenSum;

    /**Checks to see if all numbers added together after
     * the luhn algorithm are a multiple of 10.
     * If true it will return the card is valid
     * If false, the card is invalid.
     */
    if (sum % 10 == 0){
        return true;
    }
    else{
        return false;
    }
}

/**Function to make numArray back into a string to output to user*/
string CreditCard::toString() {

    /**Variable for card number into a string*/
    string finalCard = " ";

    /**Uses the initial numArray that the user input the number into
     * and adds dashes at the 4th, 8th, and 12th index to output a
     * credit card number to the user. */
    for(int i = 0; i < SIZE; i++) {
        if (i == 4 || i == 8 || i == 12) {
            finalCard += "-" + to_string(numArray[i]);
        } else {
            finalCard += to_string(numArray[i]);
        }
    }
    /**Returns the card number to the user in a string format.*/
    return finalCard;
}