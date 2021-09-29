/*
    Date:           2-23-2020
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn and understand linked lists. This is a 
					simple program to store values in this kind of data 
					structure.  

    sample input:
                    "sampleInput.txt"

    Questions to think about:
        1. What is the time/space complexity to add, remove, sort?
	
*/



#include <iostream>
#include <stdio.h>
#include <cstddef>
using namespace std;

/*
class node {
	public:
		int data;
		node *next;
};
*/
 
struct _node{
	int data;
	struct _node *next;
	
	// constructor
	_node(int x){
		data = x;
		next = NULL;
	}
};

void printList(_node *head){
	_node *node = head;
	while(node != NULL){
		cout << node->data <<  ' ';
		node = node->next;
	}
	cout << endl;
}

_node *insertAtBegining(_node *head, int newData);
_node *insertAtEnd(_node *head, int newData);

int main(){
	
	/*
	node *head = NULL;
	node *second = NULL;
	node *third = NULL;

	head = new node();
	second = new node();
	third = new node();

	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	//printf("first |   data: %d  next %d\n", head->data, head->next);
	//printf("first |   data: %d\n", head->data);
	cout << "first |   data: " << head->data << "   next: " << head->next << endl;
	cout << "second |  data: " << second->data << "   head: " << second << " next: " << second->next << endl;
	cout << "third |   data: " << third->data << "   next: " << third << " next: " << third->next << endl;
	*/
	// Driver Code:

	return 0;
}






