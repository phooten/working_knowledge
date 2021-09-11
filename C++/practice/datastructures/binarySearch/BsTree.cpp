#include <iostream>
#include "BsTree.h"

BsTree::BsTree() : data(0), left(NULL), right(NULL)
{}

BsTree::BsTree(int num) : data (num), left(NULL), right(NULL)
{}

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

void BsTree::Print(BsTree *root){

    if(!root){
        return;
    }
    Print(root->left);
    std::cout << root->data << std::endl;
    Print(root->right);
}