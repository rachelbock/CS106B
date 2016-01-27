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
using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;


/* Function prototypes */
void gamePlay(board gameBoard);
void welcome();
void giveInstructions();
void guessWord (board gameBoard);
bool isGuessOnBoard (string str, board gameBoard);

/* Main program */

int main() {
    board gameBoard(4,4);
    welcome();
    string line = getLine("Would you like to read the instructions?");
    if (toLowerCase(line) == "yes") {
        giveInstructions();
    }
    GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
    initGBoggle(gw);
    guessWord(gameBoard);
    
    
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



//in progress - add check for location
//maybe add / or something to the cube that has been used so no dups
bool isGuessOnBoard(string str, board gameBoard) {
    if (str.length() == 1) {
        if (gameBoard.contains(stringToChar(str))) {
            return true;
        }
    }
    else {
        string char1 = "";
        char1 = str[0];
        if (gameBoard.contains(stringToChar(char1))) {
            string strSub = str.substr(1, str.length() -1);
            return isGuessOnBoard(strSub, gameBoard);
        }
    }
    return false;
}

//check for size
void guessWord(board gameBoard) {
    gameBoard.drawNewBoard();
    Lexicon dictionary ("/usr/share/dict/words");
    HashSet <string> guessedWords;
    
    cout <<endl << "Ok, take all the time you want and find all the words you can. Signal that you're finished by entering an empty line" << endl << endl;
    
    while(true) {
        
        string guess = getLine("Enter a word: ");
        if (guess == "") {
            break;
        }
        if (guessedWords.contains(guess)){
            cout << "This word has already been guessed." << endl;
        }
        else {
            if (dictionary.contains(guess)) {
                if (isGuessOnBoard(guess, gameBoard)) {
                    guessedWords.add(guess);
                    
                    recordWordForPlayer(guess, HUMAN);
                    
                    cout << "yay" << endl;
                }
                else {
                    cout << "This word is not on the board" << endl;
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



