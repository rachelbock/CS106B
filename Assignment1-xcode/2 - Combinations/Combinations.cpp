/*
 * File: Combinations.cpp
 * ----------------------
 * This file is the starter project for the Combinations problem.
 * Write a recursive implementation of the c(n,k) function that uses no loops, no multiplication and no calls to Fact.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include <string>
using namespace std;


double gerrymanderingRatio(Vector<Vector<string> >& districts, string party){

    double totalMajority = 0;
    double totalPartyCities = 0;
    double totalCities = 0;
    for (int i = 0; i < districts.size(); i++) {
        double totalPartyPerDist = 0;
        for (int j = 0; j < districts[i].size(); j++) {
            totalCities++;
            if (party == districts[i][j]) {
                totalPartyPerDist++;
                totalPartyCities++;
            }
        }
        if (totalPartyPerDist/districts[i].size() > .5) {
            totalMajority++;
        }
        totalPartyPerDist = 0;
    }
    
    double districtsPartyMajority = totalMajority/districts.size();
    double percentCitiesParty = totalPartyCities/totalCities;

    
    double gerryManderingRatio = districtsPartyMajority/percentCitiesParty;
    return gerryManderingRatio;
}


int main() {
    Vector<Vector<string> > districts;
    
    Vector<string> district1;
    district1.add("D");
    district1.add("R");
    district1.add("D");
    district1.add("D");
    district1.add("D");
    districts.add(district1);
    
    Vector<string> district2;
    district2.add("R");
    district2.add("D");
    district2.add("D");
    district2.add("R");
    district2.add("D");
    districts.add(district2);
    
    Vector<string> district3;
    district3.add("R");
    district3.add("R");
    district3.add("R");
    district3.add("R");
    district3.add("R");
    districts.add(district3);
    
    Vector<string> district4;
    district4.add("D");
    district4.add("D");
    district4.add("R");
    district4.add("R");
    district4.add("D");
    districts.add(district4);
    
    Vector<string> district5;
    district5.add("D");
    district5.add("D");
    district5.add("R");
    district5.add("D");
    district5.add("R");
    districts.add(district5);
    
    double d = gerrymanderingRatio(districts, "D");
    cout << d << endl;
    return 0;
}




//int pascal (int row, int col) {
//
//    if (col == 0){
//        return 1;
//    }
//    else if (row == col) {
//        return 1;
//    }
//    else {
//        return pascal (row - 1, col - 1) + pascal (row - 1, col);
//    }
//}
//
//
//int samPascal (int row, int col) {
//    if (row == 0) {
//        return 1;
//    }
//    else if (col == 0){
//        return samPascal (row - 1, row - 1);
//    }
//    else {
//        return samPascal (row - 1, col - 1) + samPascal (row, col - 1);
//    }
//}
//
//int oddTotal (int N) {
//    int total = 0;
//
//    int oddNum = 1;
//    int prevOddNum = 0;
//
//    for (int i = 0; i < N; i++) {
//        prevOddNum = oddNum;
//        oddNum += 2;
//        total = oddNum + prevOddNum;
//
//    }
//
//    return total;
//}

