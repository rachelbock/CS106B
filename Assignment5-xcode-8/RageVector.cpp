//
// Created by rage on 1/31/16.
//

#include "RageVector.h"

RageVector :: RageVector() {

    myCapacity = 10;
    myArray = new string[myCapacity]();
    mySize = 0;
}

string RageVector :: get(int index) const {

    if (index >= mySize) {
        error("Invalid index");
        return NULL;
    }
    return myArray[index];

}

void RageVector ::add(string str) {
    checkResize();
    myArray[mySize] = str;
    mySize++;
}

void RageVector ::insert(string str, int index) {

    if (index > mySize) {
        error("invalid index");
    }
    else {
        checkResize();
        for (int i = mySize; i > index; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[index] = str;
        mySize++;
    }
}

void RageVector ::remove(int index) {

    if (index >= mySize) {
        error("Invalid Index");
    }
    else {
        for (int i = index; i < mySize - 1; i++) {
            myArray[i] = myArray[i + 1];
        }
        myArray[mySize - 1] = "";
        mySize--;
    }
}

void RageVector :: clear() {
    for (int i = 0; i < mySize; i++) {
        myArray[i] = "";
    }
    mySize = 0;

}

int RageVector :: find(string str) {
    for (int i = 0; i < mySize; i++) {
        if (myArray[i] == str) {
            return i;
        }
    }
    return -1;
}

int RageVector :: size() const {
    return mySize;
}

bool RageVector :: isEmpty() {
    return mySize == 0;
}

void RageVector :: checkResize() {
    if (mySize == myCapacity) {
        string* newArray = new string[2 * myCapacity];
        for (int i = 0; i < mySize; i++) {
            newArray[i] = myArray[i];
        }
        delete[] myArray;
        myArray = newArray;
        myCapacity = 2*myCapacity;

    }
}

void RageVector ::set(string str, int index) {
    myArray[index] = str;
}

ostream& operator <<(ostream& out, const RageVector& v) {
    out << "{";

    for (int i = 0; i < v.size(); i++) {
        out << v.get(i) << ", ";
    }
    out << "}";
    return out;
}

RageVector :: ~RageVector() {
clear();
}