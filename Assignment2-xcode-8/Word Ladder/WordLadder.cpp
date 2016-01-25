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

//This function takes in a blank hashSet of words, a string that is given to it in the wordLadder function and a lexicon of english words. The function takes the given string and goes through each english word in the lexicon. It skips over any words that are not of the same length to reduce the amount of calls being made. For each english word that is the same length as the given string, it goes through each character in the word and checks to see if the characters do not match. If they are not a match, it increases a counter function by 1. The goal is to find words that differ by only one character. After the entire word has been searched through the function checks to see if it is only off by one character (count is equal to 1). If that is the case, than the word is added to the HashSet, words. Since words is passed by reference, it can be used in the main wordLadder function.
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


//This function takes in a string called start which is given by the user and a string called end whcih is given by the user. It checks to see if a word ladder exists between those two words and it prints it out if it does.
bool wordLadder (string start, string end) {
    //The first step is to set up our data sets - a Lexicon of english words, a Vector of strings that will be the ladder, a Queue of those vectors, a HashSet to contain all of the words off by one character, and a HashSet to keep track of words that have previously been used. The HashSet is critical to make sure there are no endless loops.
    Lexicon dict ("/usr/share/dict/words");
    Vector <string> ladder;
    Queue <Vector<string> > q;
    HashSet<string> usedWords;
    HashSet<string> wordsOffByOne;
    
    //The first step I take is a simple case - if the starting word and ending word are not the same size, it obviously is not a word ladder so it should return false and print out a message explaining that to the user.
    if (start.size() != end.size()) {
        cout << "starting and ending words must be the same length - this is not a word ladder." << endl;
        return false;
    }
    
    //If they are the same length, we can check to see that it is an english word and if it is, add it to the ladder vector we initialized earlier. Then we will add that ladder to our queue and the start word to our used Words HashSet.
    else if (dict.contains(start)) {
        ladder.add(start);
        q.enqueue(ladder);
        usedWords.add(start);
    }
    //If the word is not an english word, we just spit that out.
    else {
        cout << "not a valid starting word" << endl;
    }
    
    //If we've gotten t0 this point, the q should have at least the starting word in it. We say if the q is not empty, we are going to create a vector to review the ladder that we put into the q.
    while (!q.isEmpty()) {
        Vector <string> reviewLadder = q.dequeue();
        //We use our function from above to find a word that is off by one letter from the last word that is in our review Ladder vector.
        wordsDifferingByOneLetter(dict, reviewLadder[reviewLadder.size()-1], wordsOffByOne);
        //For each word in our words that are off by one character Hash Set we will add the word to our new ladder and to our used words dictionary. We then add that new ladder to the back of the queue. Note that we first check to make sure that the word has not already been used and we set up the newLadder as a copy of the ladder we reviewed so we can add the new word to it.
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
                //We check here to see if the word we get out of this is the ending word. If it is than we can print out that is in fact a word ladder and the ladder that it is.
                if (word == end) {
                    cout << "This is a word ladder" << newLadder << endl;
                    return true;
                }
            }
        }
        
        
    }
    
    //If at the end of this process we can't find a word ladder we know that it is false and there is no word ladder between the two words.
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
