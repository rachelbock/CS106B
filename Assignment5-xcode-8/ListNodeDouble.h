//
// Created by rage on 1/31/16.
//

#ifndef ASSIGNMENT5_XCODE_8_LISTNODEDOUBLE_H
#define ASSIGNMENT5_XCODE_8_LISTNODEDOUBLE_H
using namespace std;

struct ListNodeDouble {

    string data;
    ListNodeDouble* next;
    ListNodeDouble* prev;

    ListNodeDouble(string intake) {
        data = intake;
        next = NULL;
        prev = NULL;
    }
};
#endif //ASSIGNMENT5_XCODE_8_LISTNODEDOUBLE_H
