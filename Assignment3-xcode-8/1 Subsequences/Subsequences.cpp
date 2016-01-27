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
    // if the subsequence is just one character long, check to see that text contains that character and if so, return true. Base case.
    if (subsequence.length() == 1) {
        if (stringContains(text, subsequence)) {
            return true;
        }
    }
    //If the substring is more than one character long - create a new string that holds the first character of the subsequence string. Check to see if the text contains that one charater string. If it doesn't we can return false. If it does, make a substring of the text file starting at one character past where the character was through the end of the text. Create another text file to remove that character from the subsequence. Repeat the process until you're down to the last character in the subsequence and it meets the base case. 
    //Recursive Case.
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
