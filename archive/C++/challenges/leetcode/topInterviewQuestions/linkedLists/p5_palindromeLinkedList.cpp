/*
    Date:       12-12-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/
    
    Overview:
        You are given the heads of two sorted linked lists list1 and list2.

        Merge the two lists in a one sorted list. The list should be made by 
        splicing together the nodes of the first two lists.

        Return the head of the merged linked list.
        
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
            This solution was done without any outside help. This beat 25.61% of 
            submissions. 
    */
    bool A(ListNode* head) {
        // Variables
        ListNode* curr = head;
        ListNode* reverse = new ListNode;
        ListNode* prev;
        bool ans = true;

        // Empty list
        if(curr == NULL){
            return ans;
        }

        // Makes a new list but in reverse
        reverse->next = NULL;
        while(curr != NULL){
            prev = reverse;
            reverse->val = curr->val;
            reverse = new ListNode;
            reverse->next = prev;
            curr = curr->next;
        }

        // Moves through list and reverse to compare
        curr = head;
        reverse = reverse->next;
        while(reverse != NULL){
            if(curr->val != reverse->val){
                return false;
            }

            curr = curr->next;
            reverse = reverse->next;
        }

        return ans;
    }

    /*
        2nd Solution:
            This wasn't my solution. It was taken from the discussion board as 
            I was trying to figure out a more efficient / better solution. 
            This beat 54.44% solutions
    */
    ListNode* tmp;
    
    bool B(ListNode* head) {
        tmp = head;
        return B_helper(head);
    }

    bool B_helper(ListNode* node){
        bool flag;
        bool check;

        if(node == NULL){
            return true;
        }

        flag = B_helper(node->next);
        check = (node->val == tmp->val);

        tmp = tmp->next;

        return flag && check;

    }

};

void printList(ListNode* root);

int main(){
    // Input
    int arr[4] = {1,2,2,1};
    int size1 = sizeof(arr) / sizeof(arr[0]);
    
    // Set up
    ListNode list(arr[0]);
    ListNode* curr = &list;
    bool k;
    Solution Sol;


    for(int i = 1; i < size1; i++){ 
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    
    printf("Original\n");
    printList(&list);
    printf("\n\n");

    // Sends node to solutions
    k = Sol.A(&list);    
    

    if(k){
        printf("True\n");
    } else {
        printf("False\n");
    }
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
    ListNode* tmp = curr;
    while(tmp != NULL){
        printf("%d, ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
    
    return;
}