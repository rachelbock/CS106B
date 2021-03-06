//
//  board.h
//  Boggle
//
//  Created by rage on 1/24/16.
//
//

#ifndef Boggle_board_h
#define Boggle_board_h

#include "cube.h"
#include "grid.h"

class board {

public:
    board (int numRows, int numCols);
    int getRows();
    int getCols();
    int getNumCubes();
    void drawNewBoard();
    bool contains(char c);
    char charAt(int x, int y);
    bool inBounds(int x, int y);
    void markAsVisited(int x, int y);
    
private:
    int rows;
    int cols;
    int numCubes;
    Grid<char> gameGrid;
    void cubeArrangement();
    void TestcubeArrangement();
  
} ;

#endif
