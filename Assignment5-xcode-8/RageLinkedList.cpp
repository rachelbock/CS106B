//
// Created by rage on 1/31/16.
//

#include "RageLinkedList.h"
#include "error.h"

/*constructor*/
RageLinkedList::RageLinkedList() {
    front = NULL;
}

/*adds a given value to the end of the list.*/
void RageLinkedList::add(string str) {
    if (front == NULL) {
        front = new ListNode(str);
    }
    else {
        ListNode *current = front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new ListNode(str);
    }

}

/*sets a specific index to a given value*/
void RageLinkedList ::set(string str, int index) {
    if (index >= size()) {
        error ("Invalid index");
    }
    else {
        ListNode* current = front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = str;
    }
}

/*returns the element at a given index*/
string RageLinkedList::get(int index) const {

    if (index >= size()) {
        error("Invalid Index");
    }
    else {
        ListNode *current = front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
}

/*inserts one element at a given index*/
void RageLinkedList::insert(string str, int index) {

    if (index > size()) {
        error("Invalid index");
    }
    else if (index == 0) {
        ListNode* oldFront = front;
        front = new ListNode(str);
        front->next = oldFront;
    }
    else {
        ListNode *current = front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        ListNode *newNode = new ListNode(str);
        newNode->next = current->next;
        current->next = newNode;
    }
}

/*removes one element from a given index*/
void RageLinkedList::remove(int index) {

    ListNode* trash;
    ListNode* current = front;

    if (index >= size()) {
        error("Invalid index");
    }
    else if (index == 0) {
    trash = front;
    front = current->next;
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        trash = current->next;
        current->next = current->next->next;
    }
    delete(trash);
}

/*clears all elements from the list*/
void RageLinkedList::clear() {

    while (front != NULL) {
        remove(0);
    }

}
/*could implement by having a private count variable and increasing with each add/insert and decreasing with each clear/remove.*/
int RageLinkedList::size() const{
    int count = 0;
    ListNode* current = front;
    while (current != NULL) {
        current = current->next;
        count ++;
    }
    return count;
}

/*returns true if the list is empty, false if not.*/
bool RageLinkedList::isEmpty() {
    return size() == 0;
}


/*returns the index of a given value or -1 if it is not in the list*/
int RageLinkedList::find(string str) {

    if (isEmpty()) {
        return -1;
    }
    ListNode* current = front;
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

/*destructor for the class*/
RageLinkedList::~RageLinkedList() {
    clear();
}


ostream& operator <<(ostream& out, const RageLinkedList& r) {

for (int i = 0; i < r.size(); i++) {
    out << r.get(i) << ", ";
}

    return out;
}