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
#include "strlib.h"
#include "vector.h"
using namespace std;

/* Given a street number and avenue number, which are 1-indexed,
 * returns the number of paths Karel can take back home that only
 * moves left or down.
 */


void printBinary (int n, string prefix = "") {
    if (n == 0) {
        cout << prefix << endl;
    }
    else {
        printBinary(n - 1, prefix + "0");
        printBinary(n - 1, prefix + "1");
    }
        
        
}

void printDecimal (int n, string prefix = "") {
    if (n == 0) {
        cout << prefix << endl;
    }
    else {
        for (int i = 0; i < 10; i++) {
            printDecimal(n - 1, prefix + integerToString(i));
        }
    }
}


int numPathsHome(int street, int avenue) {
    if (avenue == 1 || street == 1) {
        return 1;
    }
    else {
        return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);
        
    }
}

void diceHelper (int dice, Vector<int>& chosen) {
    if (dice == 0) {
        cout << chosen << endl;
    }
    else {
        for (int i = 1; i <= 6; i++) {
            chosen.add(i);
            diceHelper(dice - 1, chosen);
            chosen.remove(chosen.size() - 1);
        }
    }
        
    }


void diceRoll (int dice) {
    Vector<int> chosen;
    diceHelper(dice, chosen);
}

void diceSumHelper (int dice, int desiredSum, int sumSoFar, Vector<int>& chosen) {
    
    if (dice == 0) {
        cout << chosen << endl;
    }
    else {
        for (int i = 1; i <=6; i++) {
            if (sumSoFar + i + 1*(dice -1) <= desiredSum &&
                sumSoFar + i + 6*(dice -1) >= desiredSum)
            {
                chosen.add(i);
                diceSumHelper(dice-1, desiredSum, sumSoFar + i, chosen);
                chosen.remove(chosen.size()-1);
            }
        }
    }
    
}

void diceSum (int dice, int desiredSum) {
    Vector<int> chosen;
    diceSumHelper(dice, desiredSum, 0, chosen);
    
}


void stringPermutation (string str, string chosen) {
    if (str.empty()) {
        cout << chosen << endl;
    }
    else {
        for (int i = 0; i < str.length(); i++) {
            
            //choose
            char c = str[i];
            chosen += c;
            str.erase(i, 1);
            
            //explore
            stringPermutation(str, chosen);
            
            //unchoose
            chosen.erase(chosen.length()-1, 1);
            str.insert(i, 1, c);
        }
    }
}


int main() {
    diceSum(3, 3);
    
    
    return 0;
}
