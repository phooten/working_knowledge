#include <iostream>
#include "node.h"

Node::Node(){
    std::cout << std::endl << "No data was given. Error." << std::endl;
}

Node::Node(int num){
    data = num;
    head = NULL;
    tail = NULL;

    position = 0;
}

bool Node::insert(int num){
    //int pos = Node::seach(num);
    
    return false;
}

int Node::seach(int num){
    while(head != NULL){
        if(num == data){
            return position;
        } else if(num < data){
            
        } else if(num > data){
            
        }
    }
}

bool Node::remove(int num){
    //int pos = Node::seach(num);

    return false;
}
