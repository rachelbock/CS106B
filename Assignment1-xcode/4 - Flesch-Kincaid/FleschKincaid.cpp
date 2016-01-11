/*
 * File: FleschKincaid.cpp
 * ----------------------
 * This file is the starter project for the Flesch-Kincaid problem.
 *
 */

#include <iostream>
#include "console.h"
#include "vector.h"
#include "tokenscanner.h"
#include <fstream>
#include "strlib.h"
#include "simpio.h"

using namespace std;

//int BinarySearch (string key, string array[], int low, int high) {
//    if (low > high) return -1;
//    int mid = (low + high)/2;
//    if (key == array[mid]) return mid;
//    if (key < array[mid]) {
//        return BinarySearch(key, array, low, mid - 1);
//    }
//    else {
//        return BinarySearch(key, array, mid+1, high);
//    }
//}
//
//int findStringinSortedArray (string key, string array[], int n) {
//    return BinarySearch(key, array, 0, n-1);
//}


//void backwardsInt (int n) {
//    if (n < 10) {
//        cout << n;
//    }
//    else {
//        int start = n/10;
//        int end = n%10;
//        backwardsInt(end);
//        backwardsInt(start);
//    }
//}
//
//void iterativeBackwardsInt (int n) {
//    while (n > 0) {
//        int start = n/10;
//        int end = n%10;
//        cout << end;
//        n = start;
//    }
//}



void tokenCount (string filename) {
    int totalWords = 0;
    int sentences = 0;
    int syllables = 0;
    Vector<string> tokens;
    
    
    ifstream input;
    input.open(filename);
    
    string line;
    string text;
    while (getline(input, line)) {
        text += line + "\n";
    }
 
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '\'') {
            text.erase(i, 1);
        }
    }
      string lowerText = toLowerCase(text);
    
    TokenScanner scanner (lowerText);
    
    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (token != " " && token != "\n"){
            tokens.add(token);
        }
        
    }
    
    for (int i = 0; i < tokens.size(); i++) {
        int tokenSyllables = 0;

        if (tokens[i] != "." && tokens[i] != "," && tokens[i] != "!") {
            totalWords += 1;
        }
        if (tokens[i] == "!" || tokens[i] == "." || tokens[i] == "?") {
            sentences += 1;
        }
        char prevCh = ' ';
        
        for (int j = 0; j < tokens[i].size(); j++) {
            
            char ch = tokens[i][j];
            
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
                if (prevCh == ' ') {
                tokenSyllables +=1;
                    if (ch == 'e' && j == tokens[i].size()-1 && tokenSyllables > 1) {
                        tokenSyllables -=1;
                    }
                }
                prevCh = ch;
                
            }
            
            else {
                prevCh = ' ';
            }
        }
        
        syllables += tokenSyllables;
    }
    double c0 = -15.59;
    double c1 = 0.39;
    double c2 = 11.8;
    
    double gradeLevel = c0 + c1*((double)totalWords / (double)sentences) + c2*((double)syllables / (double)totalWords);
    
    cout << "Words: " << totalWords << endl;
    cout << "Syllables: " << syllables << endl;
    cout << "Sentences: " << sentences << endl;
    cout << "Grade Level: " << gradeLevel << endl;
}


bool fileExists(string filename) {
    ifstream ifile(filename);
    return ifile;
}

int main() {
    
    while (true) {
    string str = getLine("Plase enter in file name: ");
        if (fileExists(str)) {
        tokenCount(str);
            break;
        }
    }
    
    return 0;
}
