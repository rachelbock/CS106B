/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

HeapPriorityQueue::HeapPriorityQueue() {
	myCapacity = 10;
	myArray = new string[myCapacity]();
	myArray[0] = "/";
	mySize = 0;
}

HeapPriorityQueue::~HeapPriorityQueue() {
delete[] myArray;
}

int HeapPriorityQueue::size() {
	return mySize;
}

bool HeapPriorityQueue::isEmpty() {
	return mySize == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	checkResize();
	myArray[mySize+1] = value;
	mySize++;
	bubbleUp();

}

string HeapPriorityQueue::peek() {
	if (mySize == 0) {
		error("There are no elements left in the queue");
		return NULL;
	}
	else {
		return myArray[1];

	}
}

string HeapPriorityQueue::dequeueMin() {
	if (mySize == 0) {
		error("There are no elements left in the queue");
		return NULL;
	}
	else {
		string temp = myArray[1];
		myArray[1] = myArray[mySize];
		myArray[mySize] = "";
		mySize--;
		bubbleDown();
		return temp;
	}
}

void HeapPriorityQueue::checkResize() {
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

void HeapPriorityQueue::bubbleUp() {
	int index = mySize;
	while (index > 1 && myArray[index] < myArray[index/2]) {
		string temp = myArray[index];
		myArray[index] = myArray[index/2];
		myArray[index/2] = temp;
		index = index/2;
	}
}

void HeapPriorityQueue::bubbleDown() {
int index = 1;
	while (index <= mySize) {
		if (myArray[index*2] > myArray[(index*2)+1]) {
			if (myArray[(index * 2) + 1] < myArray[index]) {
				string temp = myArray[index];
				myArray[index] = myArray[(index * 2) + 1];
				myArray[(index * 2) + 1] = temp;
				index = (index * 2) + 1;
			}
		}
		else {
			if (myArray[index*2] < myArray[index]) {
				string temp = myArray[index];
				myArray[index] = myArray[index*2];
				myArray[index*2] = temp;
				index = index*2;
			}
		}
	}

//	while (index <= mySize && myArray[index] > myArray[(index*2)]) {
//		string temp = myArray[index];
//		myArray[index] = myArray[(index*2)];
//		myArray[(index*2)] = temp;
//		index = (index*2);
//	}
//
//	while (index <= mySize && myArray[index] > myArray[(index*2)+1]) {
//		string temp = myArray[index];
//		myArray[index] = myArray[(index*2)+1];
//		myArray[(index*2)+1] = temp;
//		index = (index*2)+1;
//	}

}

