//
// Created by rage on 1/31/16.
//

#ifndef ASSIGNMENT5_XCODE_8_RAGEVECTOR_H
#define ASSIGNMENT5_XCODE_8_RAGEVECTOR_H

#include <iostream>
#include <string>
#include "error.h"
#include <array>

using namespace std;

class RageVector {
public:
    RageVector();
    ~RageVector();
    int size() const;
    bool isEmpty();
    string get(int index) const ;
    void add(string str);
    void insert(string str, int index);
    void remove(int index);
    void clear();
    int find (string str);
    void set(string str, int index);

private:
    string* myArray;
    int mySize;
    int myCapacity;
    void checkResize();
};

ostream& operator <<(ostream& out, const RageVector& v);

#endif //ASSIGNMENT5_XCODE_8_RAGEVECTOR_H
