/*
    Date:       11-5-2021
    Status:     
    Source:     https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/727/
    
    Overview:
        Given an integer array nums sorted in non-decreasing order, remove the 
        duplicates in-place such that each unique element appears only once. The 
        relative order of the elements should be kept the same. 
        
        Since it is impossible to change the length of the array in some 
        languages, you must instead have the result be placed in the first part 
        of the array nums. More formally, if there are k elements after removing 
        the duplicates, then the first k elements of nums should hold the final 
        result. It does not matter what you leave beyond the first k elements.

        Return k after placing the final result in the first k slots of nums.

        Do not allocate extra space for another array. You must do this by 
        modifying the input array in-place with O(1) extra memory.
        
*/

#include <iostream> 
#include <vector>
using namespace std;


void printVector(vector<int>& tmp){
    
    for(int i = 0; i < tmp.size(); i++){
        printf("%d, ", tmp[i]);
    }
    return;
}

int removeDuplicates_solutionA(vector<int>& nums){
    int copy_size = nums.size();
    int new_size = 1;

    printf("size: %d\n", nums.size());

    for(int i = 1; i < copy_size; i++){
        if(nums[new_size] == nums[new_size - 1] ){
            cout << nums[new_size] << " == " << nums[new_size + 1] << " ... Erasing pos[" << + new_size << "]\n";
            nums.erase(nums.begin() + new_size);
        } else {
            cout << nums[new_size] << " == " << nums[new_size + 1] << " ... Passed\n";
            new_size++;
        }
    }

    return new_size;
}

int removeDuplicates_solutionB(vector<int>& nums){
    int size = nums.size();
    int index = 1;

    if(size == 0){
        return 0;
    }

    for(int i = 1; i < size; i++){
        if(nums[i] != nums[i - 1] ){
            nums[index] = nums[i];
            index++;
        } 
    }

    return index;
}


int main(){
    const int size = 3;
    int arr[size] = {1,1,2}; // 3
    // int arr[size] = {0,0,1,1,1,2,2,3,3,4}; // 10
    vector<int> vec;


    for(int i = 0; i < size; i++){
        vec.push_back(arr[i]);
    }

    printf("Pre removal\n");
    printVector(vec);
    int k = removeDuplicates_solutionB(vec);     // Calls your implementation
    printf("\nafter \n");
    printVector(vec);
    
    

    return 0;
}
