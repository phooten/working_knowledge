/*
    Date:       12-5-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/
    
    Overview:
        Given the head of a linked list, remove the nth node from the end of the 
        list and return its head.
        
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* A(ListNode* head, int n) {
        ListNode* tmp;
        ListNode* root = head;

        // Goes to node before 
        for(int i = 0; i < n; i++){
            head = head->next;            
        }

        // if it's the last 
        if(head->next->next == NULL){
            delete(head->next);
            head->next = NULL;
        
        } else {
            tmp = head->next;
            head->next = head->next->next;
            delete(tmp);
        }

        return root;
    }

    /*
        2nd Solution:

    */
    void B(ListNode* node, int n) {

    }

};

void printList(ListNode* root);

int main(){
    // Input
    int arr[5] = {1,2,3,4,5};
    int node = 2;

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

    // Sends node to solutions
    Sol.A(&root, node);    
    

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