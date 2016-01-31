//
// Created by rage on 1/30/16.
//

#ifndef ASSIGNMENT5_XCODE_8_RAGELINKEDLIST_H
#define ASSIGNMENT5_XCODE_8_RAGELINKEDLIST_H

#include <string>
#include "ListNode.h"

using namespace std;

class RageLinkedList {
public:
    // constructor
    RageLinkedList();
    // destructor
    ~RageLinkedList();
    //get the string at a given index
    string get(int index);
    //add a new value at a given index
    void insert(string str, int index);
    //add a new value to the list
    void add(string str);
    //returns the size of the list
    int size();
    //returns true if the list is empty
    bool isEmpty();
    //removes the value at a given index
    void remove (int index);
    //removes all values from the list
    void clear ();
    //returns the index of a given value - returns negative one if not in the list
    int find(string str);

private:
    ListNode* front;

};

#endif //ASSIGNMENT5_XCODE_8_RAGELINKEDLIST_H
