/*
    Date:       11-26-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/

    Overview:
        Given two integer arrays nums1 and nums2, return an array of their 
        intersection. Each element in the result must appear as many times as it 
        shows in both arrays and you may return the result in any order.

    Follow up:
        1.  What if the given array is already sorted? How would you optimize 
            your algorithm?
        2.  What if nums1's size is small compared to nums2's size? Which algorithm 
            is better?
        3.  What if elements of nums2 are stored on disk, and the memory is limited 
            such that you cannot load all elements into the memory at once?
*/

#include <iostream> 
#include <vector>
using namespace std;

void printVector(vector<int>& tmp);
 

class Solution {
public:
    /*
        First attempt
        Only beat 5.19% of other submissions
    */
    vector<int> A(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    // add to answer
                    tmp.push_back(nums1[i]);    // add it to tmp
                    
                    // remove from list
                    nums2.erase(nums2.begin() + j);
                    
                    printf("new list:\n");
                    printVector(nums1);
                    printf("\n");
                    printVector(nums2);
                    printf("\n");
                    printVector(tmp);
                    printf("\n\n");

                    // go to next number
                    break;
                }
            }
        }

        return tmp;
    }

    vector<int> B(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;

        return tmp;
    }

};


int main(){
    
    // int arr1[4] = {1,2,2,1}; 
    // int arr2[2] = {2,2};
    int arr1[3] = {4,9,5}; 
    int arr2[5] = {9,4,9,8,4};

    vector<int> vec1;
    vector<int> vec2;
    const int size1 = sizeof(arr1) / sizeof(arr1[0]);
    const int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Solution Sol;

    for(int i = 0; i < size1; i++){ vec1.push_back(arr1[i]); }
    for(int i = 0; i < size2; i++){ vec2.push_back(arr2[i]); }

    printf("Pre removal\n");
    printVector(vec1);
    printf("\n");
    printVector(vec2);
    printf("\n\n");

    vector<int> k;
    // k = Sol.A(vec1, vec2);    
    k = Sol.B(vec1, vec2);    
    

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