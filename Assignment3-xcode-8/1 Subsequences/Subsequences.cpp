/*
 * File: Subsequences.cpp
 * ----------------------
 * This file is the starter project for the Subsequences problem
 * on Assignment #3.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "strlib.h"
using namespace std;



string reverseString (string str) {
    string reversed = "";
    if (str.length() < 2) {
        reversed += str;
    }
    else {
        string restChars = str.substr(0, str.length() -1);
        string lastChar = str.substr(str.length() -1, 1);
        
        return reverseString(lastChar) + reverseString(restChars);
        
    }
    return reversed;
}

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */


bool isSubsequence(string text, string subsequence) {
    
    if (subsequence.length() == 1) {
        if (stringContains(text, subsequence)) {
            return true;
        }
    }
    else {
        string char1 = "";
        char1 += subsequence[0];
        if (stringContains(text, char1)){
            string str1Sub = text.substr(text.find(char1) + 1, text.length()-(text.find(char1) +1));
            string str2Sub = subsequence.substr(1, subsequence.length()-1);
            return isSubsequence(str1Sub, str2Sub);
        }
    
    }
    return false;
}



int main() {

    cout << isSubsequence("springtime", "pint") << endl;;
    
    cout << reverseString("algorithm") << endl;

    return 0;
}
