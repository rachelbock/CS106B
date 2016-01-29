/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Consecutive Heads problem.
 * This program simulates flipping a coin repeatedly and continues until three consecutive heads were tossed. At this point the program will display the total number of coin flips that were made.
 */

#include <iostream>
#include "console.h"
#include "random.h"
#include <fstream>
#include "strlib.h"
#include "tokenscanner.h"
#include "vector.h"
#include "simpio.h"
#include "lexicon.h"

using namespace std;


//int cannonballs (int height) {
//
//    if (height == 1) {
//        return height;
//    }
//    else {
//        int squared = height*height;
//        return squared + cannonballs(height - 1);
//
//    }
//
//}
//
//int DigitSum(int n) {
//    if (n < 10) {
//        return n;
//    }
//    else {
//        int divN = n/10;
//        int modN = n%10;
//
//        return DigitSum(divN) + modN;
//    }
//}
//
//
//int DigitalRoot(int n) {
//    if (n < 10) {
//        return n;
//    }
//    else {
//        int num = DigitSum(n);
//        return DigitalRoot(num);
//    }
//
//}
//
//int GCD (int x, int y) {
//    if (x%y == 0) {
//        return y;
//    }
//
//    else {
//        int num = x%y;
//        return GCD(y, num);
//
//    }
//}

//bool isPallindrome (string str) {
//    if (str.length() < 2) {
//        return true;
//    }
//    else {
//        char first = str[0];
//        char last = str[str.length()-1];
//        if (first == last) {
//            string sub = str.substr(1, str.length() - 2);
//            return (isPallindrome(sub));
//        }
//        else {
//            return false;
//        }
//    }
//}

//void printStars(int n) {
//    if (n == 1) {
//        cout << "*";
//    }
//    else {
//        cout << "*";
//        printStars(n-1);
//    }
//}


//int power (int base, int exp) {
//    if (exp == 0) {
//        return 1;
//    }
//    else {
//        return base * power(base, exp - 1);
//    }
//}

//
//string randomShuffle (string input) {
//    int randomI = randomInteger(0, input.size()-1);
//    string randomChar;
//    randomChar += input[randomI];
//    
//    if (input.size() < 2) {
//        return input;
//    }
//    else {
//        input.erase(randomI, 1);
//        return randomChar + randomShuffle(input);
//    }
//}



void averageValueinFile (string filename, double& result) {
    ifstream input;
    input.open(filename);
    
    string line;
    string text;
    
    while (getline(input, line)) {
        text += line + "\n";
    }
    int total = 0;
    for (int i = 0; i < text.size(); i++) {
        string strnum = "";
        strnum += text[i];
        int num = stringToInteger(strnum);
        total += num;
    }
    result = total/text.size();
}

int syllablesIn (string word) {
    int syllables = 0;
    char prevCh = ' ';
    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
            if (prevCh == ' ') {
                syllables +=1;
                if (ch == 'e' && i == word.size() - 1 && syllables > 1) {
                    syllables -=1;
                }
            }
            prevCh = ch;
            
        }
        
        else {
            prevCh = ' ';
        }
    }
    return syllables;
    
}

bool haikuDetector (string filename) {
    
    Vector<string> tokens;
    ifstream input;
    input.open(filename);
    
    TokenScanner scanner(input);
    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (token != " ") {
            tokens.add(token);
        }
    }
    int firstLineSyllables = 0;
    int secondLineSyllables = 0;
    int thirdLineSyllables = 0;
    int lineNum = 0;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "\n") {
            lineNum += 1;
        }
        if (lineNum == 0) {
            int syllables = syllablesIn(tokens[i]);
            firstLineSyllables += syllables;
        }
        if (lineNum == 1) {
            int syllables = syllablesIn(tokens[i]);
            secondLineSyllables += syllables;
        }
        if (lineNum == 2) {
            int syllables = syllablesIn(tokens[i]);
            thirdLineSyllables += syllables;
        }
        
        
        
    }
    cout << firstLineSyllables << endl;
    cout << secondLineSyllables << endl;
    cout << thirdLineSyllables << endl;
    
    if (firstLineSyllables == 5 && secondLineSyllables == 7 && thirdLineSyllables == 5) {
        cout << "yay Haiku!" << endl;
        return true;
        
    }
    else {
        cout << "boo no Haiku" << endl;
        return false;
        
    }
}









string mostXzibitWord(Lexicon& words) {
    
    string bestWord = "";
    int mostSubs = 0;
    
    for (string word : words) {
        int numSubs = 0;
        for (int i = 0; i < word.length(); i++) {
            for (int j = 1; i+j < word.length()-1; j++) {
                string sub = word.substr (i, j);
                if (words.contains(sub)) {
                    numSubs +=1;
                }
               
            }
        
        }
        if (numSubs > mostSubs) {
            mostSubs = numSubs;
            bestWord = word;
        }
    }
    
    return bestWord;
}









int main() {

//    Lexicon words = Lexicon("LexiconForTest.txt");
//    cout << mostXzibitWord(words) << endl;

string word = "";
    char c = 'c';
    word = c;

    cout << word << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //    int numOfFlips = 0;
//    int numofHeads = 0;
//    
//    while (numofHeads <3) {
//        bool flip = randomBool();
//        if (flip == true) {
//            cout << "heads" << endl;
//            numofHeads = numofHeads + 1;
//        }
//        
//        if (flip == false) {
//            cout << "tails" << endl;
//            numofHeads = 0;
//        }
//        numOfFlips = numOfFlips + 1;
//    }
//    
//    cout << "It took " << numOfFlips << " flips to get 3 consecutive heads.";

    
    
    
    return 0;
}
