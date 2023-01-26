/*
    Date:           9-2-2021
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   koffe-byte

    Purpose:        To learn and understand binary search trees and to practice
                    implementing classes into code 

    sample input:
                    Random generator written in main(). 

    Questions to think about:
        1. What is binary trees's time/space complexity?
*/


#include <iostream>
#include <memory>
#include "BsTree.h"


/*
	Function Name
		Purpose:
			answer
		Arguments:
			arg1 -> 
			arg2 -> 
*/
int main(){
    // variables
	int arr[5] = {3, 1, 5, 2, 4};
    int length = 10;
    /*
        The thought here is that I declare 1 class, then the binary search is handled
        inside of that class. 
    */

    BsTree *root = NULL;
    BsTree tree;
    root = tree.Insert(arr[0], root);

    // Generate random array values	
	for(int i = 0; i < length; i++){
        tree.Insert(rand() % 100, root);
    }
	tree.Print(root);
    
	return 0;
}
