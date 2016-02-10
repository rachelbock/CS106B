//
// Created by rage on 2/5/16.
//

#include "RageBinaryTree.h"
#include "error.h"
using namespace std;

RageBinaryTree :: RageBinaryTree() {
    root = NULL;
    mySize = 0;
}

bool RageBinaryTree ::isEmpty() {
    return mySize == 0;
}

int RageBinaryTree ::size() const {
    return mySize;
}

void RageBinaryTree ::print() {
    printHelper(root);
}

void RageBinaryTree ::printHelper(TreeNode *node) {
    /*implicit base case - if null, do nothing*/
    if (node != NULL) {
        cout << node->data << endl;
        printHelper(node->left);
        printHelper(node->right);

    }
}

void RageBinaryTree ::printSideways() {
    printSidewaysHelper(root, "");
}

void RageBinaryTree ::printSidewaysHelper(TreeNode *node, string indent) {
    if (node != NULL) {
        printSidewaysHelper(node->right, indent + "    ");
        cout << indent << node->data << endl;
        printSidewaysHelper(node->left, indent + "    ");
    }
}


bool RageBinaryTree ::contains(int value) {
    return containsHelper(root, value);
}

bool RageBinaryTree ::containsHelper(TreeNode *node, int value) {
    if (node == NULL) {
        return false;
    }
    else if (node ->data == value) {
        return true;
    }
    else {
        /*could do as in left || in right, but this stops from exploring right if it is in the left*/
        return  containsHelper(node->left, value) ||
                containsHelper(node->right, value);
    }
}

void RageBinaryTree ::add(int value) {
    addHelper(root, value);
    mySize ++;
}

void RageBinaryTree ::addHelper(TreeNode*& node, int value) {
    if (node == NULL) {
        node = new TreeNode(value);
    }
    else if (node->data > value) {
        addHelper(node->left, value);
    }
    else if (node->data < value) {
        addHelper(node->right, value);
    }
    // could write an else they are equal and we should do nothing. Not necessary since no action
}

int RageBinaryTree ::getMin() {
    if (root == NULL) {
        error("Set is empty");
        return NULL;
    }
    else {
        return getMin(root);
    }
}

int RageBinaryTree ::getMin(TreeNode *node) {
    if (node->left == NULL) {
        return node->data;
    }
    else {
        return getMin(node->left);
    }
}


void RageBinaryTree ::remove(int value) {
    if (contains(value)) {
        mySize--;
    }

    removeHelper(root, value);
}

void RageBinaryTree ::removeHelper(TreeNode*& node, int value) {
    if (value < node->data) {
        removeHelper(node->left, value);
    }
    if (value > node->data) {
        removeHelper(node->right, value);
    }
    else if (node->data == value) {
        TreeNode* trash = NULL;
        //case 1 - removing a leaft (a node with no children)
        if (node->left == NULL && node->right == NULL) {
            trash = node;
            node = NULL;
        }
        //case 2 - node with only left child - replace with left child
        else if (node->right == NULL) {
            trash = node;
            node = node->left;
        }
        //case 3 - node with only right child - replace with right child
        else if (node->left == NULL) {
            trash = node;
            node = node->right;
        }
        //case 4 - node with both children. Replace with min from right of tree (can also do max of left)
        else {
            int newData = getMin(node->right);
            node->data = newData;
            removeHelper(node->right, newData);
        }
        if (trash != NULL) {
            delete trash;
        }
    }
}

void RageBinaryTree ::clear() {
    clearHelper(root);
}

void RageBinaryTree ::clearHelper(TreeNode *node) {
    if (node != NULL) {
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
}

RageBinaryTree ::~RageBinaryTree() {
    clear();
}


