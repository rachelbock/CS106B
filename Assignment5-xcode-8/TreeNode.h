//
// Created by rage on 2/2/16.
//

#ifndef ASSIGNMENT5_XCODE_8_TREENODE_H
#define ASSIGNMENT5_XCODE_8_TREENODE_H

#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data, TreeNode* left = NULL, TreeNode* right = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

#endif //ASSIGNMENT5_XCODE_8_TREENODE_H
