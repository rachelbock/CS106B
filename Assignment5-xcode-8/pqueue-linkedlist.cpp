/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */

#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
    front = NULL;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
    while (front != NULL) {
        dequeueMin();
    }
}

int LinkedListPriorityQueue::size() {
    ListNode *current = front;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }

    return count;
}

bool LinkedListPriorityQueue::isEmpty() {
    return size() == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
    if (size() == 0) {
        front = new ListNode(value);
    }
    else if (front->next == NULL) {
        if (front->data < value) {
            front->next = new ListNode(value);
        }
        else {
            ListNode *oldFront = front;
            front = new ListNode(value);
            front->next = oldFront;
        }

    }
    else {
        ListNode *current = front;
        ListNode *previous = NULL;
        while (current->data < value && current->next != NULL) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            ListNode *oldFront = front;
            front = new ListNode(value);
            front->next = oldFront;
        }
        else if (current->data < value) {
            current->next = new ListNode(value);
        }
        else {
            ListNode *newNode = new ListNode(value);
            newNode->next = previous->next;
            previous->next = newNode;
        }
    }

}

string LinkedListPriorityQueue::peek() {
    if (front == NULL) {
        error("There is nothing left to peek at");
    }
    else {
        return front->data;
    }
}

string LinkedListPriorityQueue::dequeueMin() {

    if (isEmpty()) {
        error("There is nothing left to dequeue");
    }
    string str = front->data;
    ListNode *trash = front;
    ListNode *current = front;
    front = current->next;
    delete (trash);

    return str;

}

