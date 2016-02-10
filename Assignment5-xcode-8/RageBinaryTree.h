//
// Created by rage on 2/2/16.
//

#ifndef ASSIGNMENT5_XCODE_8_RAGEBINARYTREE_H
#define ASSIGNMENT5_XCODE_8_RAGEBINARYTREE_H
#include "TreeNode.h"
#include <string>
#include <iostream>
using namespace std;

class RageBinaryTree {
public:
    RageBinaryTree();
    ~RageBinaryTree();
    int size() const;
    bool isEmpty();
    void add(int value);
    void remove(int value);
    void clear();
    bool contains(int value);
    void print();
    void printSideways();
    int getMin();

private:
    TreeNode* root;
    int mySize;
    void printHelper(TreeNode* node);
    void printSidewaysHelper(TreeNode *node, string indent = "");
    void addHelper(TreeNode*& node, int value);
    bool containsHelper(TreeNode* node, int value);
    void removeHelper(TreeNode*& node, int value);
    void clearHelper(TreeNode* node);
    int getMin(TreeNode* node);


};


#endif //ASSIGNMENT5_XCODE_8_RAGEBINARYTREE_H
