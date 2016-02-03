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
    welcome();
    string line = getLine("Would you like to read the instructions?");
    if (toLowerCase(line) == "yes") {
        giveInstructions();
    }
    
    bool stillPlaying = true;
    while (stillPlaying) {
    cout <<endl << "You can choose standard Boggle (4x4 grid)" << endl;
    cout << "or Big Boggle (5x5)." << endl;
    string boardLine = getLine("Would you like Big Boggle?");
        cout << endl;
    if (boardLine == "yes") {
        board gameBoard(5,5);
        Lexicon dictionary ("/usr/share/dict/words");
        HashSet <string> guessedWords;
        
        GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
        initGBoggle(gw);
        gameBoard.drawNewBoard();
        guessWord(gameBoard, guessedWords, dictionary);
        computerTurn(gameBoard, dictionary, guessedWords);
        
    }
    else {
    board gameBoard(4,4);
    
    Lexicon dictionary ("/usr/share/dict/words");
    HashSet <string> guessedWords;
    
    GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
    initGBoggle(gw);
    gameBoard.drawNewBoard();
    guessWord(gameBoard, guessedWords, dictionary);
    computerTurn(gameBoard, dictionary, guessedWords);
        cout << endl;
        string stillPlay = getLine("Do you want to play again?");
        if (stillPlay == "no") {
            cout << "goodbye!";
            break;
        }
    }
    }
    
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

/*
 *Function: isGuessOnBoard
 *Used in guessWord function to see if users input word is on the board.
 *Takes in the x,y location of the starting character of the word, the word and the board.
 */

bool isGuessOnBoard(int x, int y, string str, board gameBoard) {
    
    //base case - if the string is only one character and that character is the character at the x,y location, then return true.
    if (str.length() == 1 && str[0] == gameBoard.charAt(x, y)) {
        highlightCube(x, y, true);
        return true;
        
    }
    else {
        // recursive case - check to see that the first character of the string is on the gameboard at x,y, mark it as visited (changes the character to a / so it is no longer usable), and highlight it.
        if (str[0] == gameBoard.charAt(x, y)) {
            gameBoard.markAsVisited(x, y);
            highlightCube(x, y, true);
        // create a substring that removes the first character
        string strSub = str.substr(1, str.length() -1);
            //check all of the x,y locations within one step of the starting character. Send back in each location that is inbounds with the substring.
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
    
    
    cout <<endl << "Ok, take all the time you want and find all the words you can. Signal that you're finished by entering an empty line" << endl << endl;
    
    while(true) {
        pause(500);
        for (int i = 0; i < gameBoard.getRows(); i++) {
            for (int j = 0;j < gameBoard.getCols(); j++) {
                highlightCube(i, j, false);
            }
        }
        string guess1 = getLine("Enter a word: ");
        string guess = toUpperCase(guess1);
        
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
                    cout << "You can't make that word." << endl;
                    
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


bool isCompWordOnBoard (int x, int y, string str, board gameBoard, Lexicon& dictionary, HashSet<string>& guessedWords) {
    cout << "X: " << x << " Y: " << y << " str: " << str << endl;
    gameBoard.markAsVisited(x, y);
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <=1; dy++) {
            if (dx !=0 || dy!= 0) {
                int newX = x + dx;
                int newY = y + dy;
                if (gameBoard.inBounds(newX, newY)) {
                    string newWord = str + gameBoard.charAt(newX, newY);
                    if (str.length() >=4) {
                        if (dictionary.contains(newWord)) {
                            if (!guessedWords.contains(newWord)) {
                            recordWordForPlayer(newWord, COMPUTER);
                            guessedWords.add(newWord);
                            }
                        }
                        else if (dictionary.containsPrefix(newWord)) {
                            isCompWordOnBoard(newX, newY, newWord, gameBoard, dictionary, guessedWords);
                        }
                    }
                    else if (str.length() < 4) {
                        isCompWordOnBoard(newX, newY, newWord, gameBoard, dictionary, guessedWords);
                    }
                    
                }
            }
        }
    }
    return false;
}

void computerTurn(board gameBoard, Lexicon& dictionary, HashSet<string>& guessedWords) {
    
    for (int i = 0; i < gameBoard.getRows(); i++) {
        for (int j = 0; j < gameBoard.getCols(); j++) {
            string word = charToString(gameBoard.charAt(i,j));
            
            isCompWordOnBoard(i, j, word, gameBoard, dictionary, guessedWords);
            word = "";

        }
    }
    
    
}







