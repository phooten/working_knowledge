/*
    Date:       12-7-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/
    
    Overview:
        Given the head of a singly linked list, reverse the list, and return the reversed list.
        
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
            This solution was done without any outside help. It might be the worst
            time submitted, beating 0%. I know it isn't efficient, but I couldn't
            get the recurtion working, which was my first thought. Run to the 
            end of the list, then return the value as you're building the new 
            Linked list. 
    */

    ListNode* A(ListNode* head) {
        ListNode* ans;
        ListNode* curr_ans;
        ListNode* curr_head = head;
        int count = 0;
        
        if(head == NULL){
            return NULL;
        }


        // Gets a count
        while(curr_head != NULL){
            curr_head = curr_head->next;
            count++;
            
        }

        // Makes a new Linked list
        ans = new ListNode;
        curr_ans = ans;
        for(int i = 1; i < count; i++){
            curr_ans->next = new ListNode;
            curr_ans = curr_ans->next;
        }

        // Puts into linked list in revers
        curr_head = head;
        curr_ans = ans;
        for(int i = count; i > 0; i--){
            for(int j = 0; j < i - 1; j++){
                curr_head = curr_head->next;
            }
            curr_ans->val = curr_head->val;
            curr_ans = curr_ans->next;
            curr_head = head;
        }
        return ans;
    }

    /*
        2nd Solution:
            This wasn't my solution. It was taken from the discussion board as 
            I was trying to figure out a more efficient / better solution. 
            I feel very dumb, as this is so simple. Beats 17.92 % of submissions
    */
    ListNode* B(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev, * next;

        // start node
        prev = NULL;
        curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        

        // printf("%d", curr->val);
        // next = curr->next;
        // prev = curr;
        // curr->next = NULL;
        // curr = next;
        // while(curr->next != NULL){
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        //     count++;
        // }
        // return curr;
        return prev;
    }

};

void printList(ListNode* root);

int main(){
    // Input
    int arr[5] = {1,2,3,4,5};
    // int arr[2] = {1, 2};

    // Set up
    const int size = sizeof(arr) / sizeof(arr[0]);
    ListNode root(arr[0]);
    ListNode* curr = &root; 
    ListNode* k;
    Solution Sol;

    for(int i = 1; i < size; i++){ 
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    printf("Pre Deleteion\n");
    printList(&root);
    printf("\n\n");



    // Sends node to solutions
    // k = Sol.A(&root);    
    k = Sol.B(&root);
    

    printf("Post Deletion\n");
    printList(k);
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