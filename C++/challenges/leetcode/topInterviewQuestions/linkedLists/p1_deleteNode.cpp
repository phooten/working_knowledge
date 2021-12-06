/*
    Date:       12-5-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/
    
    Overview:
        Write a function to delete a node in a singly-linked list. You will not 
        be given access to the head of the list, instead you will be given 
        access to the node to be deleted directly.

        It is guaranteed that the node to be deleted is not a tail node in the 
        list.
        
*/

#include <iostream> 
#include <vector>
using namespace std;

/*
    Class for nodes in the Linked lists
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
    Class for different solutions
*/
class Solution {
public:
    /*
        1st Solution:
            This solution was done without any outside help. It beat 80.97% of
            submissions.
    */
    void A(ListNode* node) {
        ListNode* curr = node;

        // Shifts everything up
        while(curr->next->next != NULL){
            curr->val = curr->next->val;
            curr = curr->next;
        }
        
        // Handles the last node
        curr->val = curr->next->val;
        delete[] curr->next;                // This depends on implementation
        curr->next = NULL;

        return;
    }

    /*
        2nd Solution:
            This wasn't my solution. It was taken from the discussion board as 
            I was trying to figure out a more efficient / better solution. 
            This beat 98.23% solutions
    */
    void B(ListNode* node) {
        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete(temp);
        return;
    }

};

void printList(ListNode* root);

int main(){
    // Input
    int arr[4] = {4,5,1,9};
    int node = 5;

    // Set up
    const int size = sizeof(arr) / sizeof(arr[0]);
    ListNode root(arr[0]);
    ListNode* curr = &root; 
    Solution Sol;

    for(int i = 1; i < size; i++){ 
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    printf("Pre Deleteion\n");
    printList(&root);
    printf("\n\n");


    // Moves to the node to be deleted
    curr = &root;
    while(curr->val != node){
        curr = curr->next;
    }

    // Sends node to solutions
    Sol.B(curr);    
    

    printf("Post Deletion\n");
    printList(&root);
    printf("\n\n");


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
void printList(ListNode* curr){
    
    while(curr != NULL){
        printf("%d, ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    
    return;
}