//
//  cube.h
//  Boggle
//
//  Created by rage on 1/24/16.
//
//

#ifndef Boggle_cube_h
#define Boggle_cube_h

#include <string>
#include "strlib.h"
using namespace std;


class cube {
    
public:
    cube (string str);
    char getCube();
    
private:
    string cubeStr;
    
} ;


#endif
