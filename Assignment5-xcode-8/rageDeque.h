//
// Created by rage on 2/9/16.
//

#ifndef ASSIGNMENT5_XCODE_8_RAGEDEQUE_H
#define ASSIGNMENT5_XCODE_8_RAGEDEQUE_H

#include <string>
#include <iostream>
#include "error.h"
#include "ListNodeDouble.h"
using namespace std;

class rageDeque {
public:
    rageDeque();
    ~rageDeque();
    string popFront();
    string popBack();
    void pushFront(string value);
    void pushBack(string value);

private:
    struct Cell {
        string value;
        Cell* next;
        Cell* prev;
    };
    Cell* head;
    Cell* tail;
};


#endif //ASSIGNMENT5_XCODE_8_RAGEDEQUE_H
