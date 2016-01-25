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
    
    Vector<char> cubeVec;
    
    Vector<int> indexes;
    for (int j = 0; j < numCubes; j++) {
        indexes.add(j);
    }
    
    for (int i = 0; i < numCubes; i++) {
        
        int randomIndex = randomInteger(0, indexes.size()-1);
        
        cube newCube = STANDARD_CUBES[indexes[randomIndex]];
        char cubeFace = newCube.getCube();

        indexes.remove(randomIndex);
        cubeVec.add(cubeFace);
    }
    
    //This code adds the cubes to the board grid. Need to come back and clean up code.
    
    for (int i = 0; i < cols; i++) {
        labelCube(0, i, cubeVec[i]);
    }
    for (int i = 0; i < cols; i++) {
        labelCube(1, i, cubeVec[i+4]);
    }
    for (int i = 0; i < cols; i++) {
        labelCube(2, i, cubeVec[i+8]);
    }
    for (int i = 0; i < cols; i++) {
        labelCube(3, i, cubeVec[i+12]);
    }
    
}



void board :: drawNewBoard() {
    drawBoard(rows, cols);
    cubeArrangement();
    
}

    
