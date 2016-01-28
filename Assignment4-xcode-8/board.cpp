//
//  board.cpp
//  Boggle
//
//  Created by rage on 1/24/16.
//
//

#include "board.h"
#include <string>
#include "strlib.h"
#include "cube.h"
#include "gboggle.h"
#include "vector.h"
#include "grid.h"
#include "simpio.h"

using namespace std;

const string STANDARD_CUBES[16]  = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

const string BIG_BOGGLE_CUBES[25]  = {
    "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
    "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
    "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
    "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
    "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};


board :: board(int numRows, int numCols) {
    rows = numRows;
    cols = numCols;
    numCubes = rows * cols;
    gameGrid = Grid<char> (rows, cols);
    
}

int board :: getRows() {
    return rows;
}
int board :: getCols() {
    return cols;
}
int board :: getNumCubes() {
    return numCubes;
}

char board :: charAt(int x, int y) {
    char c = gameGrid[x][y];
    return c;
}

void board :: markAsVisited(int x, int y) {
    gameGrid[x][y] = '/';
    
}

bool board :: contains(char c) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (gameGrid[i][j] == c) {
                return true;
            }
        }
    }
    return false;
}


bool board :: inBounds(int x, int y) {
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        return true;
    }
    return false;
}

//for random letter arrangements
void board :: cubeArrangement() {
    
    Vector<int> indexes;
    for (int i = 0; i < numCubes; i++) {
        indexes.add(i);
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        
            int randomIndex = randomInteger(0, indexes.size()-1);
            cube newCube = STANDARD_CUBES[indexes[randomIndex]];
            char cubeFace = newCube.getCube();
            indexes.remove(randomIndex);
            gameGrid.set(i, j, cubeFace);
            labelCube(i, j, cubeFace);
        }
    }
   
}

//For user input string and for testing;

void board :: TestcubeArrangement() {
    
    while (true) {
    cout << endl;
    string line = getLine("Enter in your own 16 character string: ");
    
    if (line.size() == 16) {

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int index = (i*rows) + j;
                    string letter;
                    letter = line[index];
                    cube newCube = letter;
                    char cubeFace = newCube.getCube();
                    gameGrid.set(i, j, cubeFace);
                    labelCube(i, j, cubeFace);
                }
            }
        break;
    
    }
    else {
        cout << endl;
        cout << "That was not 16 chars, idiot!" << endl;
    }
    }
}


void board :: drawNewBoard() {
    drawBoard(rows, cols);
    string line = getLine("Do you want to enter your own board layout? ");
    if (line == "yes") {
        TestcubeArrangement();
    }
    else {
        cubeArrangement();
        
    }
    
}
   
