/*
	Author:     Parker Hooten
	Purpose:
        to learn and understand binary search trees, and to practice
        implementing class structures into code. 
*/

// Status: INCOMPLETE - [9/2/2021]

/*
	Log:
    -------------------------------------------------------
	[x/x/xxxx]
		- 

    -------------------------------------------------------
*/

/*
    Notes:
    -------------------------------------------------------
		- Binary Search on a sorted Array is O(log(n)), but inserting it will cost O(n)
        - search(x) = insert(x) = remove = O(log(n)) in average case, O(n) worst case
        - for each node, all nodes in the left subtree is greater than
        all the nodes in the right subtree
        - Leaf nodes = Last node on a branch
        - Balanced tree = 
        - Perfect tree = 
        - The tree becomes unbalanced in inserting and deleting 
    -------------------------------------------------------

*/

#include <iostream>
#include <memory>
#include "node.h"


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
	int length = 100;
	int tmp;
    int result;
    bool success;
	
    /*
        The thought here is that I declare 1 class, then the binary search is handled
        inside of that class. 
    */
    Node binary;
    binary.data = rand() % 10000;

    // Generate random array values	
	for(int i = 0; i < length; i++){
        success = binary.insert(rand() % 10000);
        result = binary.seach(rand() % 10000);
        success = binary.remove(rand() % 10000);    
    }
	
	return 0;
}
