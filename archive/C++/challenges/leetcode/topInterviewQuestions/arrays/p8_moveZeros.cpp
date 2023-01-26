
/*
    Date:       11-28-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/

    Overview:
        Given an integer array nums, move all 0's to the end of it while 
        maintaining the relative order of the non-zero elements.

        Note that you must do this in-place without making a copy of the array.
        
*/

#include <iostream> 
#include <vector>
using namespace std;

void printVector(vector<int>& tmp);
 

class Solution {
public:
    /*
        First attempt
        beat 99.07 % of submissions :)
    */
    vector<int> A(vector<int>& nums) {
        int totalZeros = 0;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                totalZeros++;
            } else {
                nums[index] = nums[i];
                index++;
            }
        }

        for(int i = nums.size() - totalZeros; i < nums.size(); i++){
            nums[i] = 0;
        }
        
        return nums;
    }

    // vector<int> B(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> tmp;

    //     return tmp;
    // }

};


int main(){
    
    int arr[5] = {0,1,0,3,12}; 
    // int arr[1] = {0};
    vector<int> vec;
    const int size = sizeof(arr) / sizeof(arr[0]);
    
    Solution Sol;

    for(int i = 0; i < size; i++){ vec.push_back(arr[i]); }
    
    printf("Pre removal\n");
    printVector(vec);
    printf("\n\n");

    vector<int> k;
    k = Sol.A(vec);    
    // k = Sol.B(vec1, vec2);    
    

    printf("Answer:\n");
    printVector(k);

    return 0;
}


void printVector(vector<int>& tmp){
    
    for(int i = 0; i < tmp.size(); i++){
        printf("%d, ", tmp[i]);
    }
    return;
}