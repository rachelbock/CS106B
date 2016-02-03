//
// Created by rage on 1/31/16.
//

#include "RageDoubleLinkList.h"

/*Constructor for Double Link List class*/
RageDoubleLinkList::RageDoubleLinkList() {
    front = NULL;
}

/*Adds a string to the end of the list*/
void RageDoubleLinkList::add(string str) {

    if (front == NULL) {
        front = new ListNodeDouble(str);
    }
    else {
        ListNodeDouble *current = front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new ListNodeDouble(str);
        current->next->prev = current;
    }
}

/*Inserts a string at a given index - throws an error message if out of bounds.*/
void RageDoubleLinkList::insert(string str, int index) {
    if (index > size()) {
        error("Invalid index");
    }
    else if (index == 0) {
        ListNodeDouble *oldFront = front;
        front = new ListNodeDouble(str);
        front->next = oldFront;
        front->next->prev = front;
    }
    else {
        ListNodeDouble *current = front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        ListNodeDouble *newNode = new ListNodeDouble(str);
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

/*Finds a given string in the list and returns its index or -1 if not found.*/
int RageDoubleLinkList::find(string str) {

    if (isEmpty()) {
        return -1;
    }
    ListNodeDouble *current = front;
    int index = 0;
    while (current->next != NULL) {
        if (current->data == str) {
            return index;
        }
        else {
            current = current->next;
            index++;
        }
    }
    return -1;
}

/*Returns the string at a given index*/
string RageDoubleLinkList::get(int index) const {
    if (index >= size()) {
        error("Invalid Index");
    }
    else {
        ListNodeDouble *current = front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
}

/*sets a given index to a specific string*/
void RageDoubleLinkList::set(string str, int index) {
    if (index >= size()) {
        error("Invalid index");
    }
    else {
        ListNodeDouble *current = front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = str;
    }
}

/*Removes the string at a given index*/
void RageDoubleLinkList::remove(int index) {

    ListNodeDouble *trash;
    ListNodeDouble *current = front;

    if (index >= size()) {
        error("Invalid index");
    }
    else if (index == 0) {
        if (size() == 1) {
            trash = front;
            front = NULL;
        }
        else {
            trash = front;
            front = current->next;
            front->prev = NULL;
        }
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        trash = current->next;
        current->next = current->next->next;
        current->next->prev = current;
    }
    delete (trash);
}

/*Returns the size of the list*/
int RageDoubleLinkList::size() const {
    int count = 0;
    ListNodeDouble *current = front;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

/*Returns true if the string is empty*/
bool RageDoubleLinkList::isEmpty() {
    return size() == 0;
}

/*Removes all strings from the list*/
void RageDoubleLinkList::clear() {
    while (front != NULL) {
        remove(0);
    }
}

/*Destructor*/
RageDoubleLinkList::~RageDoubleLinkList() {
    clear();
}

/*print out operation*/
ostream &operator<<(ostream &out, const RageDoubleLinkList &rDL) {

    for (int i = 0; i < rDL.size(); i++) {
        out << rDL.get(i) << ", ";
    }

    return out;

}
