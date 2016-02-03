/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */

#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
    myCapacity = 10;
    myArray = new string[myCapacity];
    mySize = 0;

}

VectorPriorityQueue::~VectorPriorityQueue() {
    for (int i = 0; i < mySize; i++) {
        myArray[i] = "";
    }
    mySize = 0;
    delete [] myArray;
}

int VectorPriorityQueue::size() {
    return mySize;
}

bool VectorPriorityQueue::isEmpty() {
    return mySize == 0;
}

void VectorPriorityQueue::enqueue(string value) {
    checkResize();
    myArray[mySize] = value;
    mySize++;
}

string VectorPriorityQueue::peek() {

    if (mySize == 0) {
        error("There are no elements in the list");
    }
    string min = "";

    for (int i = 0; i < mySize; i++) {
        if (i == 0) {
            min = myArray[i];
        }
        else if (myArray[i] < min) {
            min = myArray[i];
        }
    }

    return min;
}

string VectorPriorityQueue::dequeueMin() {

    if (mySize == 0) {
        error("There are no elements in the list");
    }
    string min = "";
    int index;

    for (int i = 0; i < mySize; i++) {
        if (i == 0) {
            min = myArray[i];
            index = i;
        }
        else if (myArray[i] < min) {
            min = myArray[i];
            index = i;
        }
    }
    for (int i = index; i < mySize - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    myArray[mySize - 1] = "";
    mySize--;

    return min;
}

void VectorPriorityQueue::checkResize() {
    if (mySize == myCapacity) {
        string *newArray = new string[2 * myCapacity];
        for (int i = 0; i < mySize; i++) {
            newArray[i] = myArray[i];
        }
        delete[] myArray;
        myArray = newArray;
        myCapacity = 2 * myCapacity;

    }
}