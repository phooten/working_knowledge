/*
    Date:       11-22-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
    
    Overview:
        Given an integer array nums, return true if any value appears at least twice in the array, and 
        return false if every element is distinct.
        
*/

#include <iostream> 
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /*
        This solution was too slow to pass the tests. 
    */
    bool A(vector<int>& nums) {
        int curr;
        int j;
        int i = 0;
        int size = nums.size();

        while(i < size-1){
            curr = nums[i++];
            j = i;
            while(j < size){
                if(nums[j++] == curr){
                    return true;
                }
            }
        }
        return false;

    }

    /*
        **************************************************************
        **  THIS SOLUTION ISN'T COMPLETELY MY OWN.                  **
        **  Referenced based on solutions discussed in comments.    **
        **************************************************************
    */
    bool B(vector<int>& nums){
        // Beat 14.6% of entries on time
        set<int> sNums(nums.begin(), nums.end());
	    return sNums.size() != nums.size();     
    }

    bool C(vector<int>& nums){

    }
};

void printVector(vector<int>& tmp){
    
    for(int i = 0; i < tmp.size(); i++){
        printf("%d, ", tmp[i]);
    }
    return;
}


int main(){
    // int arr[4] = {1,2,3,1}; // 4
    // int arr[4] = {1,2,3,4}; // 4
    int arr[10] = {1,1,1,3,3,4,3,2,4,2}; // 10
    const int size = 10;
    vector<int> vec;

    Solution Sol;

    for(int i = 0; i < size; i++){
        vec.push_back(arr[i]);
    }

    printf("Initial Array\n");
    printVector(vec);
    
    bool k;
    k = Sol.A(vec);    
    // k = Sol.B(vec);    


    printf("\n\n");
    (k) ? printf("true") : printf("false");
    printf("\n");
    

    return 0;
}
