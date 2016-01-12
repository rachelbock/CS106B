/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Consecutive Heads problem.
 * This program simulates flipping a coin repeatedly and continues until three consecutive heads were tossed. At this point the program will display the total number of coin flips that were made.
 */

#include <iostream>
#include "console.h"
#include "random.h"

using namespace std;


//int cannonballs (int height) {
//
//    if (height == 1) {
//        return height;
//    }
//    else {
//        int squared = height*height;
//        return squared + cannonballs(height - 1);
//
//    }
//
//}
//
//int DigitSum(int n) {
//    if (n < 10) {
//        return n;
//    }
//    else {
//        int divN = n/10;
//        int modN = n%10;
//
//        return DigitSum(divN) + modN;
//    }
//}
//
//
//int DigitalRoot(int n) {
//    if (n < 10) {
//        return n;
//    }
//    else {
//        int num = DigitSum(n);
//        return DigitalRoot(num);
//    }
//
//}
//
//int GCD (int x, int y) {
//    if (x%y == 0) {
//        return y;
//    }
//
//    else {
//        int num = x%y;
//        return GCD(y, num);
//
//    }
//}

//bool isPallindrome (string str) {
//    if (str.length() < 2) {
//        return true;
//    }
//    else {
//        char first = str[0];
//        char last = str[str.length()-1];
//        if (first == last) {
//            string sub = str.substr(1, str.length() - 2);
//            return (isPallindrome(sub));
//        }
//        else {
//            return false;
//        }
//    }
//}

//void printStars(int n) {
//    if (n == 1) {
//        cout << "*";
//    }
//    else {
//        cout << "*";
//        printStars(n-1);
//    }
//}


//int power (int base, int exp) {
//    if (exp == 0) {
//        return 1;
//    }
//    else {
//        return base * power(base, exp - 1);
//    }
//}


string randomShuffle (string input) {
    int randomI = randomInteger(0, input.size()-1);
    string randomChar;
    randomChar += input[randomI];
    
    if (input.size() < 2) {
        return input;
    }
    else {
        input.erase(randomI, 1);
        return randomChar + randomShuffle(input);
    }
}


int main() {

    cout << randomShuffle("plausible") << endl;

    
    
    
    
    
    
    
//    cout << cannonballs(4) << endl;
//    
//    cout << DigitalRoot(1729) << endl;
//    
//    cout << GCD(24, 18) << endl;
    
//    int numOfFlips = 0;
//    int numofHeads = 0;
//    
//    while (numofHeads <3) {
//        bool flip = randomBool();
//        if (flip == true) {
//            cout << "heads" << endl;
//            numofHeads = numofHeads + 1;
//        }
//        
//        if (flip == false) {
//            cout << "tails" << endl;
//            numofHeads = 0;
//        }
//        numOfFlips = numOfFlips + 1;
//    }
//    
//    cout << "It took " << numOfFlips << " flips to get 3 consecutive heads.";

    
    
    
    return 0;
}
