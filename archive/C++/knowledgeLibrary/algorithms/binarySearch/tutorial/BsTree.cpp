#include <iostream>
#include "BsTree.h"

/*
    Purpose:    Default Constructor
*/
BsTree::BsTree() : data(0), left(NULL), right(NULL) {}


/*
    Purpose:    
*/
BsTree::BsTree(int num) : data (num), left(NULL), right(NULL) {}


/*
    Purpose:
*/
BsTree *BsTree::Insert(int num, BsTree *root){
    BsTree *current = root;

    if(!current){
        return new BsTree(num);
    }

    if(num < current->data){
        current->left = Insert(num, current->left);
    } else if (num > current->data){
        current->right = Insert(num, current->right);
    }

    return current;
}


/*
    Purpose:    Print out contents of the binary search tree
*/
void BsTree::Print(BsTree *root){

    if(!root){
        return;
    }
    Print(root->left);
    std::cout << root->data << std::endl;
    Print(root->right);
}