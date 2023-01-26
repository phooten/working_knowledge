/*
    Date:           11-
    Status:     
    Source Link:    https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/173/

    Problem Statement:
        Given an array of integers nums and an integer target, return indices of 
        the two numbers such that they add up to target. You may assume that 
        each input would have exactly one solution, and you may not use the same 
        element twice. You can return the answer in any order.

    Input: nums = [ 2, 7, 11, 15], target = 9
    Output: [0, 1]
    Output: Because nums[0] + nums[1] == 9, we return [0, 1].
*/


#include <iostream>
using namespace std;



int* sumCheck(int *arr, int size, int target);

int main(){
    // int nums[] = {2, 7, 11, 15};
    // int target = 9;
    // int nums[] = {3, 2, 4};
    // int target = 6;
    // int nums[] = {3, 3};
    // int target = 6;
    int nums[] = {-3, 4, 3, 90};
    int target = 0;
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "size: " << size << endl;

    int* ans = sumCheck(nums, size, target);
    if(ans[0] == ans[1])
        cout << "No such pair\n";
    cout << "ans: " << ans[0] << ", " << ans[1] << endl;


    return 0;
}



int* sumCheck(int *arr, int size, int target){
    int* ans = new int[2];

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            cout << arr[i] << " + " << arr[j] << " = " << arr[j] + arr[i] << "\n";
            if(target == arr[i] + arr[j]){
                ans[0] = i;
                ans[1] = j;
                return &ans[0];
            }
        }
    }

    return &ans[0];
}


