
/*
    Date:       11-27-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/

    Overview:
        You are given a large integer represented as an integer array digits, 
        where each digits[i] is the ith digit of the integer. The digits are 
        ordered from most significant to least significant in left-to-right 
        order. The large integer does not contain any leading 0's.

        Increment the large integer by one and return the resulting array of 
        digits.
        
*/

#include <iostream> 
#include <vector>
using namespace std;

void printVector(vector<int>& tmp);
 

class Solution {
public:
    /*
        First attempt
        beat 46.16 % of submissions
    */
    vector<int> A(vector<int>& digits) {
        int plusOne; 
        int carry;

        for(int i = digits.size() - 1; i >= 0; i--){
            plusOne = digits[i] + 1;
            if(plusOne < 10){
                digits[i] = plusOne;
                return digits;
            } else {
                digits[i] = plusOne % 10;
            }
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }

    // vector<int> B(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> tmp;

    //     return tmp;
    // }

};


int main(){
    
    // int arr[3] = {1,2,3}; 
    // int arr[4] = {4,3,2,1};
    int arr[1] = {0};
    // int arr[1] = {9};
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