/*
    Date:       11-22-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
    
    Overview:
        Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

        You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int A(vector<int>& nums) {
        // Beat 17.23% of submissions
        if(nums.size() == 1){
            return nums[0];
        }

        // Sort
        sort(nums.begin(), nums.end());

        // check every pair, if pair !=, then return
        for(int i = 0; i < nums.size(); i += 2){
            if(nums[i] != nums[i+1])
                return nums[i];
        }
        return nums[nums.size() - 1];
    }

    int B(vector<int>& nums){

    }
};

void printVector(vector<int>& tmp){
    
    for(int i = 0; i < tmp.size(); i++){
        printf("%d, ", tmp[i]);
    }
    return;
}


int main(){
    
    int arr[3] = {2,2,1}; // 3
    // int arr[5] = {4,1,2,1,2}; // 5
    // int arr[1] = {1}; // 1
    vector<int> vec;
    const int size = sizeof(arr) / sizeof(arr[0]);

    Solution Sol;

    for(int i = 0; i < size; i++){
        vec.push_back(arr[i]);
    }

    printf("Pre removal\n");
    printVector(vec);
    
    int k;
    k = Sol.A(vec);    
    // k = Sol.B(vec);    
    printf("\n%d\n", k);
    
    

    return 0;
}
