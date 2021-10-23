/*
    Date:           2-29-2020
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn and understand doubly linked lists. This is a 
					simple program to store values in this kind of data 
					structure.  

	Comment [ 9-28-2021 ]:
					You could go add a sort() function to sort the DLL

    sample input:
                    8 <-> 12 <-> 10 <-> 5 <-> 3 <-> 9

    Questions to think about:
        1. What is the time/space complexity to add, remove, sort?
	
*/


#include <iostream>
#include <stdio.h>
#include <cstddef>
using namespace std;
 
 // Function declarations
_node *addNode(_node *head, int data);
_node *deleteNode(_node *head, int index);


 /*
	Purpose:	Store data that can be connected to other nodes by storing a 
				link between the next node, and the previous node
*/
struct _node{
	// variables
	int data;
	struct _node *next;
	struct _node *prev;

	// constructor
	_node(int x){
		data = x;
		prev = NULL;
		next = NULL;
	}
};


int main(){
	// Variables
	int tmp;
	int n;
	int del;
	_node *tmpHead;
	_node *head = NULL;
	
	// User input
	cin >> del;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		head = addNode(head, tmp);
	}
	
	// Prints out DLL
	tmpHead = head;
	while(tmpHead != NULL){
		cout << tmpHead->data << " ";
		tmpHead = tmpHead->next;
	}
	cout << endl;

	//sortList(head);
	tmpHead = head;
	
	head = deleteNode(tmpHead, del);
	
	// Prints out DLL
	tmpHead = head;
	while(tmpHead != NULL){
		cout << tmpHead->data << " ";
		tmpHead = tmpHead->next;
	}
	cout << endl;


	return 0;
}

/*
	Purpose:	Add a node to the struct "_node"

	Arguments:	head: Pointer to the start of the linked list
				data: Data stored in the node of the head

	Return:		The last position in the linked list
*/
_node *addNode(_node *head, int data){
	// Variables
	_node *tHead = head;
	_node *tPrev;
	_node *node;

	node = new _node(data);
	if(tHead != NULL){				// gets to the last node
		while(tHead->next != NULL){
			tHead = tHead->next;
		}

		node->prev = tHead;
		tHead->next = node;

	} else {						// gets to the first node
		node->next = NULL;
		node->prev = NULL; 
		head = node;
	}

	return head;
}

/*
	Purpose:	Add a node to the struct "_node"

	Arguments:	head:  Pointer to the start of the linked list
				index: The node position in the list

	Return:		The last position in the linked list
*/
_node *deleteNode(_node *head, int index){
	// Variables
	int count;
	_node *tmpHead;

	// Checks: DLL (doubly linked list)
	if(tmpHead == NULL){	// if DLL is empty
		return head;
	}

	// goes to the index of the DLL
	tmpHead = head;	
	for(count = 1; count < index; count++){
		if(tmpHead->next != NULL){	
			tmpHead = tmpHead->next;
		
		} else {							// checks that index !> length of DLL
			return head;
		}
	}
	
	// removes the connections before and after node
	if(tmpHead->next != NULL){				// checks for last node
		tmpHead->next->prev = tmpHead->prev;
	} else {
		tmpHead->prev->next = NULL;
		//tmpHead->prev = NULL;
	}

	if(tmpHead->prev != NULL){				// checks for first node
		tmpHead->prev->next = tmpHead->next;
	} else {
		head = tmpHead->next;
		tmpHead->next->prev = NULL;
		//tmpHead->next = NULL;
	}


	return head;
}



