/*
 * File: RandomSubsets.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Random Subsets problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "set.h"
#include "random.h"
#include "console.h"
using namespace std;

/* Given a set of integers, returns a uniformly-random subset of that
 * set.
 */
Set<int> randomSubsetOf(Set<int>& s) {
    Set<int> returnSet;
    
    if (s.size() == 1) {
        bool isTrue = randomBool();
        if (isTrue == true) {
            returnSet.add(s.first());
        }
        return returnSet;
    }
    else {
        bool isTrue = randomBool();
        if (isTrue == true) {
            returnSet.add(s.first());
        }
        s.remove(s.first());
        Set<int> subSet = randomSubsetOf(s);
        returnSet += subSet;
    }
    
    return returnSet;
}



int main() {
    Set<int> randomInts;
    for (int i = 0; i < 10; i++) {
        randomInts.add(i);
    }
    
    cout << randomInts << endl;
    
    cout << randomSubsetOf(randomInts) << endl;
    
    return 0;
}
