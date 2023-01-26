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
            This solution was done without any outside help. It beat 78.92% of
            submissions. I thin there are too many special cases though. I also 
            don't like the list gets passed through almost twice. 
    */
    ListNode* A(ListNode* head, int n) {
        // Variables
        ListNode* curr = head;
        ListNode* root = head;
        int count = 0;
        
        // Counts the total elements
        while(curr != NULL){
            count++;
            curr = curr->next;
        };

        // special cases: one element and the first element
        if(n == 1 && count == 1){
            return NULL;

        } else if (count == n){
            root = root->next;
            return root;

        }

        // Goes to the node and removes it
        curr = head;
        for(int i = 0; i < count - n - 1; i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;

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
    int arr[2] = {1, 2};
    int node = 2;
    // int arr[1] = {1};
    // int node = 1;
    // int arr[5] = {1,2,3,4,5};
    // int node = 2;

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