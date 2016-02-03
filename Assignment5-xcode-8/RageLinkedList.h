//
// Created by rage on 1/30/16.
//

#ifndef ASSIGNMENT5_XCODE_8_RAGELINKEDLIST_H
#define ASSIGNMENT5_XCODE_8_RAGELINKEDLIST_H

#include <string>
#include "ListNode.h"
#include <iostream>
#include "console.h"

using namespace std;

class RageLinkedList {
public:
    RageLinkedList();
    ~RageLinkedList();
    string get(int index) const;
    void insert(string str, int index);
    void add(string str);
    int size() const;
    bool isEmpty();
    void remove (int index);
    void clear ();
    int find(string str);
    void set(string str, int index);



private:
    ListNode* front;

};

ostream& operator <<(ostream& out, const RageLinkedList& r);

#endif //ASSIGNMENT5_XCODE_8_RAGELINKEDLIST_H
