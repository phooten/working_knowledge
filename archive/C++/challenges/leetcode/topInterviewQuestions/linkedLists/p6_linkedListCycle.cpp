/*
    Date:       12-15-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/773/
    
    Overview:
        Given head, the head of a linked list, determine if the linked list has 
        a cycle in it.

        There is a cycle in a linked list if there is some node in the list that
        can be reached again by continuously following the next pointer. 
        Internally, pos is used to denote the index of the node that tail's next 
        pointer is connected to. Note that pos is not passed as a parameter.

        Return true if there is a cycle in the linked list. Otherwise, return 
        false.
        
*/

#include <iostream> 
#include <vector>
#include <set>
#include <unordered_set>
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
            This solution was done without any outside help. This beat 0% of 
            submissions though. It took 1023 ms, and the 99th % is at 26 ms 


    */
    bool A(ListNode* head) {
        // Variables
        ListNode* curr = head;
        vector<ListNode*> addList;

        if(curr != NULL){

            while(curr != NULL){
                for(int i = 0; i < addList.size(); i++){
                    if(curr == addList[i]){
                        return true;
                    }
                }
                addList.push_back(curr);
                curr = curr->next;
            }
        
        }

        return false;
    }

    /*
        2nd Solution:
            This solution was done without any outside help. This beat 0% of 
            submissions though. It took 43 ms, and the 99th % is at 26 ms. It
            cut solution A by  95%,but still slowerer than most. The only 
            difference is using sets instead of vectors to track previous
            addresses
    */
    bool B(ListNode* head) {
        // Variables
        ListNode* curr = head;
        set<ListNode*> addList;

        if(curr != NULL){

            while(curr != NULL){
                auto pair = addList.emplace(curr); 
                if( !pair.second ){
                    return true;
                }
                curr = curr->next;
            }
        
        }

        return false;
    }

    /*
        3rd Solution:
            This solution is not mine. It was taken from the solution for the
            purposes of learning. It beat 5.13% at a run time of 33ms,  and 
            beat 13.76% on space with 10.6 MB.
                Space Complexity:   O(n)
                Time Complexity:    O(n)
    */
    bool C(ListNode* head) {
        // Variables
        ListNode* curr = head;
        unordered_set<ListNode*> visited;
        
        while(curr != NULL){
            if(visited.count(curr)){
                return true;
            }
            // NOTE:
            //  .contains for c++ 20
            // if(visited.contains(curr)){
            //     return true;
            // }
            visited.emplace(curr);
            curr = curr->next;
        }


        return false;
    }
    
    /*
        4th Solution:
            This solution is not mine. It was taken from the solution for the
            purposes of learning. It bead 28.50% with a run time of 14ms, and beat
            memory usage of 57.13% with a size of 8.1 MB
                        
            Floyd's Tortoise and Hare  Algorithm:
                Space Complexity:   O(1)    (We aren't using extra space)
                Time Complexity:    O(n)    (n = number of nodes)
                        Analysis:
                            n = total # of nodes
                            m = # of nodes in cycle
                        1.  n >= m
                        2.  steps <= n
                        3.  steps <= m
            I don't like how if you have an even loop, the fast won't shift, 
            and I think there is a possibility that fast and slow miss each other
            on several loops. This seems to be a very unique case though 
    */
    bool D(ListNode* head) {
        // Variables
        ListNode* fast = head;
        ListNode* slow = head;

        if(head != NULL){

            while(fast->next != NULL && fast->next->next != NULL){
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                    return true;
                }
            }
        }


        return false;
    }
};

void printList(ListNode* root);

int main(){
    // Input
    // int arr[1] = {1};
    // int pos = -1;
    int arr[4] = {3,2,0,-4};
    int pos = 1;
    // int arr[2] = {1,2};
    // int pos = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Set up
    ListNode list(arr[0]);
    ListNode* curr = &list;
    ListNode* lastAdd;
    bool k;
    Solution Sol;


    for(int i = 1; i < size; i++){ 
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    

    printf("Original: %d\n", size);
    printList(&list);
    printf("\n\n");

    if(pos >= 0){
        curr = &list;
        for(int i = 0; i < pos; i++){
            curr = curr->next;
        }
        printf("%d\n", curr->val);
        lastAdd = curr;
        
        curr = &list; 
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = lastAdd;
    }


    // Sends node to solutions
    // k = Sol.A(&list);    
    // k = Sol.B(&list);    
    k = Sol.C(&list);    
    // k = Sol.D(&list);    

    if(k){
        printf("True\n");
    } else {
        printf("False\n");
    }
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
void printList(ListNode* curr){
    // Variable
    ListNode* tmp = curr;

    while(tmp != NULL){
        printf("%d, ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
    
    return;
}