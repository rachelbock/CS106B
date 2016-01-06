/*
 * File: Combinations.cpp
 * ----------------------
 * This file is the starter project for the Combinations problem.
 * Write a recursive implementation of the c(n,k) function that uses no loops, no multiplication and no calls to Fact.
 */

#include <iostream>
#include "console.h"
using namespace std;


int pascal (int row, int col) {
    
    if (col == 0){
        return 1;
    }
    else if (row == col) {
        return 1;
    }
    else {
        return pascal (row - 1, col - 1) + pascal (row - 1, col);
    }
}





int main() {

    cout << pascal (2, 0);
    
    return 0;
}
