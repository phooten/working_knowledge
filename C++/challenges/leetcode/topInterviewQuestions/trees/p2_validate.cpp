
/*
    Date:       12-21-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/
    
    Overview:
        Given the root of a binary tree, determine if it is a valid binary 
        search tree (BST).

        A valid BST is defined as follows:

        The left subtree of a node contains only nodes with keys less than the 
        node's key. The right subtree of a node contains only nodes with keys 
        greater than the node's key. Both the left and right subtrees must also 
        be binary search trees.
*/

#include <iostream> 
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

/*
    Class for nodes in the Binary Tree
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
    Class for different solutions
*/
class Solution {
public:
    /*
        1st Solution:
            This solution was done without any outside help. This beat 68.46% of 
            submissions. It took 8 ms, and 18.9 MB of space 
    */
    bool A(TreeNode* root) {
        // Variables
        bool ans = false;
        
        // if(root = NULL){
        //     return true;
        // }
        
        if(root->left != NULL){
            if(root->left->val < root->val){
                
            }
            ans = A(root->left);
            if(!ans){
                return ans;
            }
        } else if(root->right != NULL){
            ans = A(root->right);
            if(!ans){
                return ans;
            }
        }

        return ans;
    }
};

void printList(TreeNode* root);

int main(){
    // Input
    int arr[3] = {2,1,3};
    // int arr[3] = {5,1,4,null,null,3,6};
    // int arr[3] = {2,1,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Set up
    TreeNode root(arr[0]);
    TreeNode* curr = &root;
    Solution Sol;


    int x = 0;
    for(int i = 1; i < size; i++){
         
    }
    

    

    printf("Original: %d\n", size);
    printList(&root);
    printf("\n\n");


    // Sends node to solutions
    // k = Sol.A(&list);    
    // k = Sol.B(&list);    
    // k = Sol.C(&list);    
    // k = Sol.D(&list);    

    printf("\n\n");

    // Test if looped
    // printList(&list);

    // Clean up memory
    // curr = &root;
    // for(int i = size - 1; i > 0; i--){ 
    //     for(int j = 0; j < i; j++){
    //         curr = curr->next;
    //     }
    //     delete[] curr;
    //     curr = &root;
    // }

    

    return 0;
}



/*
    Purpose:    Prints out the linked list
*/
void printList(TreeNode* curr){
    // Variable
    TreeNode* tmp = curr;
    if(curr = NULL){
        return;
    } else {
        printf("%d, ", curr->val);
        printList(curr->left);
        printList(curr->right);
    }
    return;
}