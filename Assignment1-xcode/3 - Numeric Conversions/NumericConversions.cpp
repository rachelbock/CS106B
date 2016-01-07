/*
 * File: NumericConversions.cpp
 * ---------------------------
 * This file is the starter project for the Numeric Conversions problem.
 *
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;




string intToString(int n) {
    
    string intString = "";
    
    if (n < 10) {
        char ch = '0';
        return intString += ch + n;
    }
    
    else {
        return intToString(n/10) + intToString(n%10);
        }
    }




    int stringToInt(string str) {
    
        int stringInt = 0;
        
        if (str.length() == 1) {
            char ch = str[0];
            stringInt += ch - '0';
        }
        else {
            string subStart = str.substr(0, str.length()-1);
            string subEnd = str.substr(str.length() - 1, str.length());
            
            return stringToInt(subStart)*10 + stringToInt(subEnd);
        }
        return stringInt;
    }









/* Main program */

    int main() {

        cout << intToString(137) << endl;
        cout << stringToInt("9904") << endl;

        
    return 0;
    }
