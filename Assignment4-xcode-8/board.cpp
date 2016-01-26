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

const string TEST_STANDARD_CUBES[16] = {
    "CC", "AA", "RR", "TT",
    "OO", "RR", "AA", "HH",
    "AA", "MM", "AA", "EE",
    "LL", "SS", "PP", "BB"
};

board :: board(int numRows, int numCols) {
    rows = numRows;
    cols = numCols;
    numCubes = rows * cols;
    //add grid here?
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

void board :: cubeArrangement() {
    
    Grid<char> cubeGrid(rows, cols);
    
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
            cubeGrid.set(i, j, cubeFace);
            labelCube(i, j, cubeFace);
        }
    }
   
    
    
}




void board :: drawNewBoard() {
    drawBoard(rows, cols);
    cubeArrangement();
    
}

    
