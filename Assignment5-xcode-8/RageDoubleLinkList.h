//
// Created by rage on 1/31/16.
//

#ifndef ASSIGNMENT5_XCODE_8_RAGEDOUBLELINKLIST_H
#define ASSIGNMENT5_XCODE_8_RAGEDOUBLELINKLIST_H

#include <string>
#include <iostream>
#include "error.h"
#include "ListNodeDouble.h"
using namespace std;

class RageDoubleLinkList {
public:
    RageDoubleLinkList();
    ~RageDoubleLinkList();
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
    ListNodeDouble* front;

};

ostream& operator <<(ostream& out, const RageDoubleLinkList& rDL);

#endif //ASSIGNMENT5_XCODE_8_RAGEDOUBLELINKLIST_H
