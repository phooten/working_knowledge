/*
    Date:       11-6-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
    Overview:
        Given an array, rotate the array to the right by k steps, where k is 
        non-negative.
*/

#include <iostream> 
#include <vector>
#include <string>
using namespace std;


void printVec(vector<int> &vec);

/*
    First attempt:
        Brute force, rotating by 1 every time, so if we have to rotate by 3
        spots, then it will be O(3n) runtime. 
        idea: if there are n=10 elements and you have to rotate it 6 times, it
        would be faster to rotate it the other direction 4 times. 

*/
class A{
public:
    A(){}

    void rotate(vector<int>& nums, int k){
        int tmp, last = 0;
        k = k % nums.size();

        for(int i = 0; i < k; i++){
            last = nums[nums.size() - 1];
            for(int j = 0; j < nums.size(); j++){
                tmp = nums[j];
                nums[j] = last;
                last = tmp;
            }
        }
        

        return;
    }

};

/*
    Second attempt:
        Success:        38/38 cases
        Runtime:        ~28 ms
        Memory Usage:   24.9 MB
*/
class B{
public:
    B(){}

    void rotate(vector<int>& nums, int k){
        // Variables
        int start_index;
        int curr_index;
        int prev, curr;
        int count = 1;

        k = k % nums.size();

        // Accounts for k dividing evenly into nums.size()
        for(start_index = 0; count < nums.size(); start_index++){
            prev = nums[start_index];
            curr_index = start_index + k;
            count++;

            while(curr_index != start_index){
                // Moves previous position into current
                curr = nums[curr_index];                
                nums[curr_index] = prev;
                prev = curr;

                // Prints out array
                printVec(nums);
                
                // Moves to new position
                curr_index = (curr_index + k) % nums.size();
                count++;
            }

            // place last number
            nums[curr_index] = prev;
        }

        return;
    }
};


/*
    Third attempt:
   
*/
class C{
public:
    C(){}
    
};



int main(){
    // Variables
    const int size = 7;
    int arr[] = {1,2,3,4,5,6,7};
    // const int size = 4;
    // int arr[] = {-1,-100,3,99};
    int k = 2;


    // Moves array into vector
    vector<int> vec;
    for(int i = 0; i < size; i++){
        vec.push_back(arr[i]);
    }
        

    cout << "Original Vector:\n";
    printVec(vec);
    
    // A A_solution;
    // A_solution.rotate(vec, k);

    B B_solution;
    B_solution.rotate(vec, k);

    // C C_solution;
    // C_solution.reverseString(v_input);

    cout << "\n\nRotated Vector: [" << k << "]\n\n";
    printVec(vec);


    return 0;
}


/*
    Purpose:    Prints out vector contents

    Arguments:  vec - vector to be printed out 
*/
void printVec(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ", "; 
    }
    cout << "\n\n";

    return;
}

