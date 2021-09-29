/*
    Date:           2-24-2020
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten
					Geekforgeeks (see Credit)

    Purpose:        To learn more about C++, pointers, and linked lists. Create 
					functions to insert nodes at the begining and end of a 
					linked list.  

    sample input:
                    "sampleInput.txt"

    Questions to think about:
        1. What is the time/space complexity to add, remove, sort?
	
	Credit: 
		1. GeeksforGeeks:
			https://practice.geeksforgeeks.org/problems/linked-list-insertion/1
			This is meant for practice, and the problem statement on the site was 
			completed entirely on my own.
	
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
   	// Driver Code (written by website linked at top)
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



