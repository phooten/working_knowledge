
/*
    Date:       12-19-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/
    
    Overview:
        Given the root of a binary tree, return its maximum depth.

        A binary tree's maximum depth is the number of nodes along the longest 
        path from the root node down to the farthest leaf node.
*/

#include <iostream> 
#include <vector>
#include <set>
#include <math>
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
    int A(TreeNode* root) {
        // Variables
        int left = 0;
        int right = 0;
        int depth = 0;

        if(root == NULL){
            return 0;

        } else {
            depth += 1;
            left += A(root->left);
            right += A(root->right);
            if( left >= right){
                depth += left;
            } else {
                depth += right;
            }
        
        }

        return depth;
    }

    /*
        2nd Solution:
            This solution was done without any outside help. This beat 93.0% of 
            submissions. It took 4 ms, and 18.8 MB of space. I thought it would
            take up less space, rather than less time
    */
    int B(TreeNode* root) {
        // Variables
        int left = 0;
        int right = 0;

        if(root == NULL){
            return 0;

        } else {
            left = A(root->left) + 1;
            right = A(root->right) + 1;
            
            if( left >= right){
                return left;
            
            } else {
                return right;
            
            }
        }
    }

};

void printList(TreeNode* root);

int main(){
    // Input
    int arr[7] = {3, 9, 20, -1, -1, 15, 7};
    int par[2] = {3, 4};
    int depth = 2;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Set up
    TreeNode root(arr[0]);
    TreeNode* curr = &root;
    Solution Sol;


    int x = 0;
    for(int i = 1; i < size; i++){
        
        if(i == par[x]){
            
            x++;
        }
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