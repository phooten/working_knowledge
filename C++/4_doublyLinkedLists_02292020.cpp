/*
	Author:		Parker Hooten
	Purpose: 	
	Language:	C++

*/

// Status: INCOMPLETE - [2/29/2020] - [1.5 hours]
//
//							   Total:  

// Log:
//---------------------------------------------------------------------------
// [2/29/2020]
//		- created what I believe to be a doubly linked list. I havent been able to 
//		  test if everything is linked correctly or not. The program takes an input
//		  as "n" total elements. Each number after is taken as an input and added to
//		  the end of the list. The next step is to sort the list. 
// [2/30/2020]
//		- 
//---------------------------------------------------------------------------


// sample
/*
	initial dl list:
	
	8 <-> 12 <-> 10 <-> 5 <-> 3 <-> 9
	
	after sorted:
	
	3 <-> 5 <-> 8 <-> 9 <-> 10 <-> 12

*/

#include <iostream>
#include <stdio.h>
#include <cstddef>
using namespace std;
 
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

// only adds nodes to the end of list
_node *addNode(_node *head, int data){
	_node *tHead = head;
	_node *tPrev;
	_node *node;

	node = new _node(data);

	if(tHead != NULL){
		// gets to the last node
		while(tHead->next != NULL){
			tHead = tHead->next;
		}
		// node->next = NULL;
		node->next = tHead->next;
		node->prev = tHead;
		tHead->next = node;
	
	} else {
		node->next = head;
		head = node;
	}

	return head;
}

/*
	ideas:
		- any sorting technic an array can use
		- i.e. Bubble sorting
*/

// to sort the list
_node *sortList(_node *head){
	
	cout << endl << endl << "sorted list:" << endl;

	return;
}

int main(){
	// Variables
	// int test;
	int tmp;
	int n;
	_node *head = NULL;

	cin >> n;
	for(int i = 0; i <= n; i++){
		cin >> tmp;
		head = addNode(head, tmp);
	}

	while(head->next != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;

	sortList(head);

	return 0;
}



