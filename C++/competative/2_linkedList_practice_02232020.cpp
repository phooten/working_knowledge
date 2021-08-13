/*
	Author:		Parker Hooten
	Purpose:	
	Language:	C++
*/

// Status: INCOMPLETE - [2/23/2020]

// Log:
//---------------------------------------------------------------------------
// [2/23/2020]
//		- I have a pretty good idea about the basics of linked list and was 
// 		  able to create a small one. Everything created today was hardcoded
//		  so the next step will be to try to implement an add/delete function.
//		  MAKE SURE TO COMPILE WITH "g++ ..."
// [2/24/2020]
//		- 
//---------------------------------------------------------------------------


// sample
/*
	input: 
	3
	5
	9 0 5 1 6 1 2 0 5 0 
	3
	5 1 6 1 9 1
	4
	15 0 36 0 95 0 14 0

	output:
	5 2 9 5 6
	5 6 9
	14 95 36 15
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
}

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






