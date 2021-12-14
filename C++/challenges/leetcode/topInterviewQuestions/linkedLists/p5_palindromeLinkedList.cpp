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
            This solution was done without any outside help. 
    */
    bool A(ListNode* list) {
        ListNode* curr = list;
        bool ans = false;
        
       

        return ans;
    }

    /*
        2nd Solution:
            This wasn't my solution. It was taken from the discussion board as 
            I was trying to figure out a more efficient / better solution. 
            This beat 98.23% solutions
    */
    bool B(ListNode*list ) {

    }

};

void printList(ListNode* root);

int main(){
    // Input
    int arr1[3] = {1,2,4};
    int arr2[3] = {1,3,4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // Set up
    ListNode list1(arr1[0]);
    ListNode list2(arr2[0]);
    ListNode* curr1 = &list1;
    ListNode* curr2 = &list2;
    ListNode* k;
    Solution Sol;


    for(int i = 1; i < size1; i++){ 
        curr1->next = new ListNode(arr1[i]);
        curr1 = curr1->next;
    }
    
    for(int i = 1; i < size2; i++){ 
        curr2->next = new ListNode(arr2[i]);
        curr2 = curr2->next;
    }
    
    printf("Pre Merge\n");
    printList(&list1);
    printList(&list2);
    printf("\n\n");



    // Sends node to solutions
    k = Sol.A(&list1, &list2);    
    

    printf("Post Merge\n");
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
    ListNode* tmp = curr;
    while(tmp != NULL){
        printf("%d, ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
    
    return;
}