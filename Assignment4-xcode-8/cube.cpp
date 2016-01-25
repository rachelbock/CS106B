//
//  cube.cpp
//  Boggle
//
//  Created by rage on 1/24/16.
//
//

#include "cube.h"
#include "random.h"
#include "strlib.h"
#include <string>
using namespace std;

const int numSides = 6;

cube :: cube (string str) {
    cubeStr = str;
}

char cube :: getCube() {
    int randomInt = randomInteger(0, numSides-1);
    char topChar = cubeStr[randomInt];
    return topChar;
}