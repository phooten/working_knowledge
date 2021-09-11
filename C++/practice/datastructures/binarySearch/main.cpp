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
		- learned:
            Class a = new Class();
            Class *aPtr = &a;

            (*aPtr).method() =  aPtr->method()

            The dot operator gives direct member selection via object name.

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
        - A new data point is always inserted at the leaf node
    -------------------------------------------------------

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
