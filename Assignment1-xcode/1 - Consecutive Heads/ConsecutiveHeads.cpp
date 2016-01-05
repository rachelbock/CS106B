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

int main() {
    int numOfFlips = 0;
    int numofHeads = 0;
    
    while (numofHeads <3) {
        bool flip = randomBool();
        if (flip == true) {
            cout << "heads" << endl;
            numofHeads = numofHeads + 1;
        }
        
        if (flip == false) {
            cout << "tails" << endl;
            numofHeads = 0;
        }
        numOfFlips = numOfFlips + 1;
    }
    
    cout << "It took " << numOfFlips << " flips to get 3 consecutive heads.";
    return 0;
}
