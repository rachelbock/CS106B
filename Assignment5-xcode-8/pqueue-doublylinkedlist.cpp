/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */

#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
    front = NULL;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
    while (front != NULL) {
        dequeueMin();
    }
}

int DoublyLinkedListPriorityQueue::size() {
    int count = 0;
    ListNodeDouble *current = front;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
    return size() == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {

    if (front == NULL) {
        front = new ListNodeDouble(value);
    }
    else {
        ListNodeDouble *current = front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new ListNodeDouble(value);
        current->next->prev = current;
    }
}


string DoublyLinkedListPriorityQueue::peek() {

    if (size() == 0) {
        error("There are no more items to dequeue");
        return NULL;
    }
    else {
        ListNodeDouble *current = front;
        string min = front->data;
        while (current != NULL) {
            if (current->data < min) {
                min = current->data;
            }
            current = current->next;
        }
        return min;
    }
}


string DoublyLinkedListPriorityQueue::dequeueMin() {

    if (size() == 0) {
        error("There are no more items to dequeue");
        return NULL;
    }
        else {
        string min = front->data;
        ListNodeDouble *current = front;
        ListNodeDouble *point = front;

        while (current != NULL) {
            if (current->data < min) {
                min = current->data;
                point = current;
            }
            current = current->next;
        }
        if (min == front->data) {
            ListNodeDouble *trash = front;
            if (front->next != NULL) {
                front->next->prev = NULL;
                front = front->next;
                delete (trash);
            }
            else {
                front = NULL;
                delete (trash);
            }
        }
        else {
            ListNodeDouble* trash2 = point;
            if (point->next == NULL) {
                point->prev->next = NULL;
                delete (trash2);
            }
            else {
                ListNodeDouble* trash2 = point;
                point->prev->next = point->next;
                point->next->prev = point->prev;
                delete (trash2);
            }
        }
        return min;
    }
}

