/*
 * File: Boggle.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */
 
#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "strlib.h"
#include "simpio.h"
#include "board.h"
#include "cube.h"
#include "hashset.h"
#include "timer.h"
using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;


/* Function prototypes */
void gamePlay(board gameBoard);
void welcome();
void giveInstructions();
void guessWord (board gameBoard, HashSet<string>& guessedWords, Lexicon& dictionary);
bool isGuessOnBoard (int x, int y, string str, board gameBoard);
bool isCompWordOnBoard (int x, int y, string str, board gameBoard, Lexicon& dictionary, HashSet<string>& guessedWords);
void computerTurn(board gameBoard, Lexicon& dictionary, HashSet<string>& guessedWords);
                        

/* Main program */

int main() {
    Lexicon dictionary ("/usr/share/dict/words");
    HashSet <string> guessedWords;
    
    board gameBoard(4,4);
    welcome();
    string line = getLine("Would you like to read the instructions?");
    if (toLowerCase(line) == "yes") {
        giveInstructions();
    }
    GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
    initGBoggle(gw);
    guessWord(gameBoard, guessedWords, dictionary);
    computerTurn(gameBoard, dictionary, guessedWords);
    
    
    return 0;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
    cout << "Welcome!  You're about to play an intense game ";
    cout << "of mind-numbing Boggle.  The good news is that ";
    cout << "you might improve your vocabulary a bit.  The ";
    cout << "bad news is that you're probably going to lose ";
    cout << "miserably to this little dictionary-toting hunk ";
    cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
    cout << endl;
    cout << "The boggle board is a grid onto which I ";
    cout << "I will randomly distribute cubes. These ";
    cout << "6-sided cubes have letters rather than ";
    cout << "numbers on the faces, creating a grid of ";
    cout << "letters on which you try to form words. ";
    cout << "You go first, entering all the words you can ";
    cout << "find that are formed by tracing adjoining ";
    cout << "letters. Two letters adjoin if they are next ";
    cout << "to each other horizontally, vertically, or ";
    cout << "diagonally. A letter can only be used once ";
    cout << "in each word. Words must be at least four ";
    cout << "letters long and can be counted only once. ";
    cout << "You score points based on word length: a ";
    cout << "4-letter word is worth 1 point, 5-letters ";
    cout << "earn 2 points, and so on. After your puny ";
    cout << "brain is exhausted, I, the supercomputer, ";
    cout << "will find all the remaining words and double ";
    cout << "or triple your paltry score." << endl << endl;
    cout << "Hit return when you're ready...";
    getLine();
    
}



bool isGuessOnBoard(int x, int y, string str, board gameBoard) {
    
    if (str.length() == 1 && str[0] == gameBoard.charAt(x, y)) {
        highlightCube(x, y, true);
        return true;
        
    }
    else {
        if (str[0] == gameBoard.charAt(x, y)) {
            gameBoard.markAsVisited(x, y);
            highlightCube(x, y, true);
        string strSub = str.substr(1, str.length() -1);
            
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <=1; dy++) {
                    if (dx !=0 || dy!= 0) {
                        int newX = x + dx;
                        int newY = y + dy;
                        if (gameBoard.inBounds(newX, newY)) {
                            bool isTrue = isGuessOnBoard(newX, newY, strSub,  gameBoard);
                            if (isTrue) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

//highlightcube still in progress
void guessWord(board gameBoard, HashSet<string>& guessedWords, Lexicon& dictionary) {
    gameBoard.drawNewBoard();
    
    
    cout <<endl << "Ok, take all the time you want and find all the words you can. Signal that you're finished by entering an empty line" << endl << endl;
    
    while(true) {
        pause(500);
        for (int i = 0; i < gameBoard.getRows(); i++) {
            for (int j = 0;j < gameBoard.getCols(); j++) {
                highlightCube(i, j, false);
            }
        }
        string guess = getLine("Enter a word: ");
        
        if (guess == "") {
            break;
        }
        if (guess.size() < 4) {
            cout << "Words must be at least 4 characters long." << endl;
        }
        else if (guessedWords.contains(guess)){
            cout << "This word has already been guessed." << endl;
        }
        else {
            if (dictionary.contains(guess)) {
                bool hasBeenFound = false;
                for (int i = 0; i < gameBoard.getRows(); i++) {
                    for (int j = 0; j < gameBoard.getCols(); j++) {
                        if (guess[0] == gameBoard.charAt(i, j)) {
                            if (isGuessOnBoard(i, j, guess, gameBoard)) {
                                hasBeenFound = true;
                            }
                        }
                    }
                }
                if (hasBeenFound == false) {
                    cout << "This word is not on the board" << endl;
                    
                }
                else {
                    guessedWords.add(guess);
                    recordWordForPlayer(guess, HUMAN);
                    cout << "yay" << endl;
                }
            }
            else {
                cout << "This is not an english word" << endl;
            }
        }
    }
    cout << "Done";

}

//Computer Recursion Function

bool isCompWordOnBoard (int x, int y, string str, board gameBoard, Lexicon& dictionary, HashSet<string>& guessedWords) {
    
    gameBoard.markAsVisited(x, y);
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <=1; dy++) {
            if (dx !=0 || dy!= 0) {
                int newX = x + dx;
                int newY = y + dy;
                if (gameBoard.inBounds(newX, newY)) {
                    str += gameBoard.charAt(newX, newY);
                    if (str.length() >=4) {
                        if (dictionary.contains(str)) {
                            if (!guessedWords.contains(str)) {
                            recordWordForPlayer(str, COMPUTER);
                            guessedWords.add(str);
                            }
                        }
                        else if (dictionary.containsPrefix(str)) {
                            isCompWordOnBoard(newX, newY, str, gameBoard, dictionary, guessedWords);
                        }
                    }
                    else if (str.length() < 4) {
                        isCompWordOnBoard(newX, newY, str, gameBoard, dictionary, guessedWords);
                    }
                    
                }
            }
        }
    }
    return false;
}

void computerTurn(board gameBoard, Lexicon& dictionary, HashSet<string>& guessedWords) {
    string word = "";
    for (int i = 0; i < gameBoard.getRows(); i++) {
        for (int j = 0; j < gameBoard.getCols(); j++) {
            char c = gameBoard.charAt(i,j);
            word = c;
            isCompWordOnBoard(i, j, word, gameBoard, dictionary, guessedWords);
            word = "";

        }
    }
    
    
}







