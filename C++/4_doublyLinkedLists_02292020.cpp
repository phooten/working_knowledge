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
// [3/2/2020]
//		- started writing a delete function node function. It works except for the edge
//		  cases of the initial node and the final node, expectedly. 
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

_node *deleteNode(_node *head, int index){
	int count;
	_node *tmpHead;

	tmpHead = head;	
	for(count = 1; count < index; count++){
		if(tmpHead->next != NULL){
			//cout << tmpHead << " - " << tmpHead->next << endl;
			tmpHead = tmpHead->next;
		} else {
			return head;
		}
	}
//	cout << "prev: " << tmpHead->prev; //->next ;//= tmpHead->next;
//	cout << "Bout to hit, count: " << count << endl;
	tmpHead->next->prev = tmpHead->prev;
	tmpHead->prev->next = tmpHead->next;
	while(tmpHead->next !=NULL){
		tmpHead = tmpHead->next;
	}
	tmpHead->prev->next = NULL;

	return head;
}

/*
	ideas:
		- any sorting technic an array can use
		- i.e. Bubble sorting
*/

/*
// to sort the list
_node *sortList(_node *head){
	
	cout << endl << endl << "sorted list:" << endl;

	return;
}
*/

int main(){
	// Variables
	// int test;
	int tmp;
	int n;
	_node *tmpHead;
	_node *head = NULL;

	cin >> n;
	for(int i = 0; i <= n; i++){
		cin >> tmp;
		head = addNode(head, tmp);
	}
	
	tmpHead = head;
	while(tmpHead->next != NULL){
		cout << tmpHead->data << " ";
		tmpHead = tmpHead->next;
	}
	cout << endl;

	//sortList(head);
	tmpHead = head;
	deleteNode(tmpHead, 2);
	deleteNode(tmpHead, 1);	
	tmpHead = head;
	while(tmpHead != NULL){
		cout << tmpHead->data << endl;
		tmpHead = tmpHead->next;
	}


	return 0;
}



