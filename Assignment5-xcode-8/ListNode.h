//
// Created by rage on 1/31/16.
//

#ifndef ASSIGNMENT5_XCODE_8_LISTNODE_H
#define ASSIGNMENT5_XCODE_8_LISTNODE_H

using namespace std;

struct ListNode {

    string data;
    ListNode* next;

    ListNode(string intake) {
        data = intake;
        next = NULL;
    }
};

#endif //ASSIGNMENT5_XCODE_8_LISTNODE_H
