#include<iostream>

class Node{
public:
    int m_value;
    Node* m_next;
    // int* prev;

    Node() : m_value(0), m_next(NULL){}
    Node(int value) : m_value(value), m_next(NULL) {}

};

void addNode(Node* node, int value){
    while(node->m_next != NULL){
        node++;
    }
    Node data(value);
    node->m_next = &data;

    return;

}



void deleteNode(Node* node){
    while(node->m_next->m_next != NULL){
        node++;
    }

    node->m_next = NULL;
    return;
}


void printList(Node* node){
    if(node->m_next == NULL){
        std::cout << node->m_value;
    } 

    while(node->m_next != NULL){
        std::cout << node->m_value << ", ";
    }
    std::cout << std::endl;

    return;
}

int main(){
    Node List(5);
    
    printList(&List);

    addNode(&List, 4);
    // addNode(&List, 3);
    // addNode(&List, 2);
    // addNode(&List, 1);

    
    printList(&List);

    return 0;
}