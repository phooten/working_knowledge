
/*
    Date:           1-12-2020
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn and understand linked lists. This is a simple 
					program to store values in this kind of data structure.  

    sample input:
                    "sampleInput.txt"

    Questions to think about:
        1. What is the time/space complexity to add, remove, sort?
	
*/

// Challenge:
//		1. select subparts containing even numbers
//		2. reverse the selected subpart

#include <iostream>
#include <stdlib.h>
using namespace std;

#define	arrSize 2001


//linked list set up
//---------------------------------------

// EXAMPLE 1 : Hacker Earth
/*
struct linkedList{
	int data;
	struct linkedList *next; // self-referencing pointer
};

typedef struct linkedList *node; //node is a point of data type struct linkedList

node createNode(){
	node temp;
	temp = (node)malloc(sizeof(struct linkedList));
	temp->next = Null;
	return temp;
}

node addNoed(node head, int value){
	node temp, p;
	temp = createNode();
	temp->data = value;
	if(head == NULL){
		head = temp;
	} else {
		p = head;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}*/
//---------------------------------------

struct node{
	int data;
	node *next;
};

void moveArr(){
	/*
	n = new node;	// n points to newly created node
	n->data = 1;	// to access the data part of node
	temp = n;
	head = n;

	n = new node;	//
	n->data = 2;
	temp->next = n;
	temp = t->next;
	*/
}

int main(){
/*
	int num;
	scanf("%d", &num);
	printf("Input number is %d.\n", num);
*/
	// Variables
	int arr[arrSize];
	int n;
	int temp;
		

	// Gets input
	scanf("%i", &n);
	for(long int i = 0; i < n; ++i){
		scanf("%i", &temp);
		arr[i] = temp;
	}
	
	

	// Prints out results
	printf("\n\n");
	for(int j = 0; j < 10; j++){
		printf(" %i ", arr[j]);
	}
	printf("\n\n");

	return 0;
}
