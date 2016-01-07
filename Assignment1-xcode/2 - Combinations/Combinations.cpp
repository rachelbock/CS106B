/*
 * File: Combinations.cpp
 * ----------------------
 * This file is the starter project for the Combinations problem.
 * Write a recursive implementation of the c(n,k) function that uses no loops, no multiplication and no calls to Fact.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"

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
    if (col == 0) {
        return 1;
    }
    
    
    return 0;
}
    
double toFeet (double meters) {
    double inch = meters / .0254;
    double feet = inch/12;
    
    return feet;
}

//
//int total = 0;
//
//for (int i = 0; i <= 100; i++) {
//    total = total + i;
//    cout << i << " " << total << endl;
//    }
//    cout << total;


int oddInts (int n) {
    int oddTotal = 0;
    int currentOdd = 0;
    
    for (int i = 0; i < n; i++) {
        currentOdd = 
    }
    
    return oddTotal;
}

int main() {
    
    cout << toFeet(100);
    
    return 0;
}
