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
    
    if (numCubes == 16) {
        
        Vector <int> rowVec;
        for (int i = 0; i < rows; i++ ) {
            rowVec.add(i);
        }
        Vector<int> colVec;
        for (int i = 0; i < cols; i++) {
            colVec.add(i);
        }
        
        for (int i = 0; i < numCubes; i++) {
           
            int randomRow = randomInteger(0, rowVec.size()-1);
            int randomCol = randomInteger(0, colVec.size()-1);
            
            cube newCube = STANDARD_CUBES[i];
            char cubeFace = newCube.getCube();
            
            labelCube(rowVec[randomRow], colVec[randomCol], cubeFace);
            rowVec.remove(randomRow);
            colVec.remove(randomCol);
        }
        
        
    }
    
    else if (numCubes == 25) {
        
        int randomRow = randomInteger(0,rows -1);
        int randomCol = randomInteger(0,cols-1);
        cout << randomRow << " " << randomCol << endl;
        
    }
}

void board :: drawNewBoard() {
    drawBoard(rows, cols);
    cubeArrangement();
    
}

    
