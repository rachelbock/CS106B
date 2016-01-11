/*
 * File: WordLadder.cpp
 * ----------------------
 * This file is the starter project for the Word Ladder problem.
 *
 */

#include <chrono>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "lexicon.h"
#include "vector.h"
#include "strlib.h"
#include "queue.h"
#include "hashset.h"

using namespace std;


void wordsDifferingByOneLetter (Lexicon dictionary, string str, HashSet<string>& words) {
    words.clear();
    
    for (string word : dictionary) {
        int count = 0;
        if (word.length() == str.length()) {
            for (int i = 0; i < word.length(); i++) {
                if (word[i] != str[i]) {
                    count += 1;
                }
            }
        }
        if (count == 1) {
            words.add(word);
        }
        count = 0;
    }
}



bool wordLadder (string start, string end) {
//    chrono::milliseconds startTime = chrono::duration_cast< chrono::milliseconds >(chrono::system_clock::now().time_since_epoch());
    
    Lexicon dict ("/usr/share/dict/words");
    Vector <string> ladder;
    Queue <Vector<string> > q;
    HashSet<string> usedWords;
    
    HashSet<string> wordsOffByOne;
    
    if (start.size() != end.size()) {
        cout << "starting and ending words must be the same length - this is not a word ladder." << endl;
        return false;
    }
    
    else if (dict.contains(start)) {
        ladder.add(start);
        q.enqueue(ladder);
        usedWords.add(start);
    }
    else {
        cout << "not a valid starting word" << endl;
    }
    
    
    while (!q.isEmpty()) {
        Vector <string> reviewLadder = q.dequeue();

        wordsDifferingByOneLetter(dict, reviewLadder[reviewLadder.size()-1], wordsOffByOne);
        for (string word : wordsOffByOne) {
            if (usedWords.contains(word)) {
                //do nothing
            }
            else {
                Vector<string> newLadder;
                for (int i = 0; i < reviewLadder.size(); i++) {
                    newLadder.add(reviewLadder[i]);
                }
                newLadder.add(word);
                usedWords.add(word);
                q.add(newLadder);
                
                if (word == end) {
                    cout << "This is a word ladder" << newLadder << endl;
                    return true;
                }
            }
        }
        
        
    }
    cout << "There is no word ladder" << endl;
    return false;
}











int main() {
    
    
    while (true) {
        
        string startWord = getLine("Enter the starting word (or nothing to quit): ");
        
        if (startWord == "") {
            cout << "Goodbye!" << endl;
            break;
            
        }
        string endWord = getLine("Enter the ending word: ");
        
        wordLadder(startWord, endWord);
        
    }
    
    return 0;
}
