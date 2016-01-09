/*
 * File: WordLadder.cpp
 * ----------------------
 * This file is the starter project for the Word Ladder problem.
 *
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "lexicon.h"
#include "vector.h"
#include "strlib.h"
#include "queue.h"
#include "hashset.h"

using namespace std;


bool wordLadder (string start, string end) {
    
    bool isWordLadder = false;
    Lexicon dict ("/usr/share/dict/words");
    Vector <string> ladder;
    Queue <Vector<string> > q;
    HashSet<string> hs;
    
    if (dict.contains(start)) {
        ladder.add(start);
        q.enqueue(ladder);
        hs.add(start);
    }
    else {
        cout << "not a valid starting word" << endl;
    }
    
    
    while (!q.isEmpty()) {
        q.dequeue();
        // if (the last element in the vector just dequeued == end) { return the word ladder as the solution}
    
        
    }
    
    
    
    
    return isWordLadder;
}


// Words that differ by just one letter

HashSet<string> wordsDifferingByOneLetter (Lexicon dictionary, string str) {
    HashSet<string> words;
    
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
            
    return words;
    
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
