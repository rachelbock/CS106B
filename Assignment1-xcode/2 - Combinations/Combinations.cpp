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


int samPascal (int row, int col) {
    if (row == 0) {
        return 1;
    }
    else if (col == 0){
        return samPascal (row - 1, row - 1);
    }
    else {
        return samPascal (row - 1, col - 1) + samPascal (row, col - 1);
    }
}

int oddTotal (int N) {
    int total = 0;
    
    int oddNum = 1;
    int prevOddNum = 0;
    
    for (int i = 0; i < N; i++) {
        prevOddNum = oddNum;
        oddNum += 2;
        total = oddNum + prevOddNum;
    
    }
    
    return total;
}






int main() {

    cout <<samPascal(4,3) << endl;
    
    cout << oddTotal (4) << endl;
    
    
    return 0;
}
