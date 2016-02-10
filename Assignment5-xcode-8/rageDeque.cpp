//
// Created by rage on 2/9/16.
//

#include "rageDeque.h"

rageDeque ::rageDeque() {
    head = NULL;
    tail = NULL;
}

void rageDeque ::pushFront(string value) {

    //set up new cell with given value;
    Cell* cell = new Cell;
    cell->value = value;

    //set that cell to be at the head;
    cell->next = head;
    cell->prev = NULL;

    //if the list is empty, than the new cell is the only cell;
    if (head == NULL) {
        head = cell;
        tail = cell;
    }

    //Otherwise, set head's previous cell to be the new cell and set the head to be the cell;
    else {
        head->prev = cell;
        head = cell;
    }
}

void rageDeque ::pushBack(string value) {

    //create new cell with given value;
    Cell* cell = new Cell;
    cell->value = value;

    //set the previous to the current tail and the next to NULL;
    cell->prev = tail;
    cell->next = NULL;

    //if the tail is NULL, then the cell is the only cell so head and tail are equal to cell;
    if (tail == NULL) {
        head = cell;
        tail = cell;
    }

    //Otherwise, set tail's next to point to the new cell and tail becomes the tail;
    else {
        tail->next = cell;
        tail = cell;
    }
}

string rageDeque:: popFront() {
    //if the head is still NULL, return an error message that there's nothing left;
    if (head == NULL) {
        error("There is nothing in the queue to pop");
    }
    //set the result to be the first value and set it to trash;
    string result = head->value;
    Cell* trash = head;

    //advance head to be the next value
    head = head->next;

    //now that head has been advanced - if it is not now NULL, set it's previous to be NULL.
    if (head != NULL) {
        head->prev = NULL;
    }
    //Otherwise set tail to be NULL because there's nothing in the queue.
    else {
        tail = NULL;
    }

    delete trash;
    return result;
}

string rageDeque :: popBack() {
    //if the tail is NULL, return an error message;
    if (tail == NULL) {
        error("There is nothing in the queue to Pop");
    }
    //Otherwise set the current tail's value to result and trash;
    string result = tail->value;
    Cell* trash = tail;

    //go to tail previous and set it to tail.
    tail = tail->prev;
    //if tail is not NULL then set that tail->next is NULL;
    if (tail != NULL) {
        tail->next = NULL;
    }
    //otherwise set the head to be NULL as there is nothing in the list.
    else {
        head = NULL;
    }

    delete trash;
    return result;
}

rageDeque ::~rageDeque() {
    while (head!= NULL) {
        Cell* next = head->next;
        head = next;
    }
}