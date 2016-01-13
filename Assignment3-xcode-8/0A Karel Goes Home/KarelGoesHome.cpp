/*
 * File: KarelGoesHome.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Karel Goes Home
 * warmup problem for Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
using namespace std;

/* Given a street number and avenue number, which are 1-indexed,
 * returns the number of paths Karel can take back home that only
 * moves left or down.
 */
int numPathsHome(int street, int avenue) {
    if (avenue == 1 || street == 1) {
        return 1;
    }
    else {
        return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);
        
    }
}



int main() {
    cout << numPathsHome(3, 2) << endl;
    
    return 0;
}
