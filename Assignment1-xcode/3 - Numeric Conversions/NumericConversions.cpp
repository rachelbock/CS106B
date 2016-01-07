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
            
            
            
            return stringInt;
        
        }
        return stringInt;
    }








/* Main program */

    int main() {

        cout << intToString(137) << endl;
        cout << stringToInt("90") << endl;

        int sent = 0;
        int max = 0;
        while (true) {
            int num = getInteger("?");
            
            if (num == sent) break;
            if (num > max) {
                max = num;
            }
        }
        cout << "The largest value is " << max << endl;
        
    return 0;
    }
