
#include <iostream>

class BinTree_node{
public:
    int m_data;
    BinTree_node* m_left;
    BinTree_node* m_right;
};


class BinSearchTree{
public:
    // Variables
    BinTree_node* m_root;
    int m_size;

    BinSearchTree(){
        m_root = NULL;
        m_size = 0;
    }

    void addNode(int value);
    void printTree();

};

void BinSearchTree::addNode(int value){
    // Variables
    BinTree_node* curr = m_root;
    BinTree_node* next = curr;
    
    BinTree_node* node_new = new BinTree_node;
    node_new->m_data = value;
    node_new->m_left = NULL;
    node_new->m_right = NULL;


    if(curr == NULL){
        m_root = node_new;
    } else {
        while(next != NULL){
            curr = next;
            if(value < curr->m_data){
                next = curr->m_left;
            } else {
                next = curr->m_right;
            }
        }
        
        if(value < curr->m_data){
            curr->m_left = node_new;
        } else {
            curr->m_right = node_new;
        }
    }

    m_size++;
    return;    
}

void BinSearchTree::printTree(){
    
    return;
}


int main(){
    BinSearchTree Tree;
    Tree.addNode(50);
    

    return 0;
}