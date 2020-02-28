/*
	Author:		Parker Hooten
	Purpose:	To learn more about C++, pointers, and linked lists. Create functions to insert
				nodes at the begining and end of a linked list.
	Language:	C++
	NOTE:		Alot of this code came from the website (below) meant as a template:
				_____________________________________________________________________________

				LINK:     https://practice.geeksforgeeks.org/problems/linked-list-insertion/1
				____________________________________________________________________________
				This is meant for practice, and the problem statement on the site was 
				completed entirely on my own.
*/

// Status: INCOMPLETE - [2/27/2020] - [40.ish minutes]
//						[2/24/2020] - [2.ish hours]
//
//							   Total:  2.66 hours

// Log:
//---------------------------------------------------------------------------
// [2/24/2020]
//		- Somewhat of a continuation on "2_...2020.cpp". Ran code and got the first
// 		  linked list right, but also got a seg fault right after. I'll probably have
//		  to valgrind if I can't visually check my code, so I'm taking a break for tonight. 
//		  I have a much better grasp on this after drawing everything out. 
// [2/27/2020]
//		- The memory leak was caused on line 106: " while(tmpHead->next != NULL){ ... etc.
//		  When the "insertAtEnd" function was called and it was an empty list, there was
//		  No tmpHead->next, so it was accessing illeagal memory. I created an if statement 
//		  to counter this, but there is probably a better way to counter this. I'll probably 
//		  look into this next time I work on this. Other than that, the code runs well and 
// 		  I have a much better understanding of this code. 
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
 
struct _node{
	// variables
	int data;
	struct _node *next;
	
	// constructor
	_node(int x){
		data = x;
		next = NULL;
	}
};



void printList(_node *head){
	// Variables
	_node *node = head;

	while(node != NULL){
		cout << node->data <<  ' ';
		node = node->next;
	}
	cout << endl;
}



_node *insertAtBegining(_node *head, int newData){
	// Variables
	_node *next;
	
	next = head;
	head = new _node(newData);
	head->next = next;

	return head;
}



_node *insertAtEnd(_node *head, int newData){
	// Variables	
	_node *tmpHead;
	_node *tmpNext;

	tmpHead = head;
	if(tmpHead != NULL){
		while(tmpHead->next != NULL){
			tmpHead = tmpHead->next;
		}
		
		tmpHead->next = new _node(newData);
		tmpNext = tmpHead->next;
		tmpNext->next = NULL;
	} else {
		head = new _node(newData);
		head->next = NULL;
	}
	
	return head;
}



int main(){
   	// Driver Code (written by link listed at top)
   	int test;
   	cin >> test;
   	while(test--){
   		int n, ch, tmp;
   		
  		_node *head = NULL;
		cin >> n;
		
		for(int i = 0; i < n; i++){
			cin >> tmp >> ch;
			if(ch) head = insertAtEnd(head, tmp);
			else head = insertAtBegining(head, tmp);
		}
		printList(head);
	}
	return 0;
}



