// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/


/*
    Date:       11-6-2021
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
    Overview:
        
*/

#include <iostream> 
#include <vector>
#include <string>
using namespace std;


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
        only worked for 3/477 cases
*/
class B{
public:
    B(){}

    void rotate(vector<int>& nums, int k){
        int tmp;
        int start;
        int prev, curr, next;
        int count;

        k = k % nums.size();
        count = 0;

        for(start = 0; count < nums.size(); start++){
            curr = start;
            prev = nums[start];
            while(curr != start){
                next = (curr + k) % nums.size(); // The % wraps arround after > nums.size so you don't need an if statement
            }
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
    // Set up
    const int size = 7;
    int arr[] = {1,2,3,4,5,6,7};    // 7
    // int arr[] = {-1,-100,3,99};  // 4
    int k = 3;

    vector<int> vec;
    for(int i = 0; i < size; i++){
        vec.push_back(arr[i]);
    }
        

    A A_solution;
    A_solution.rotate(vec, k);
    
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ", ";
    }
    printf("\n\n");


    cout << 2 % 6 << "\n";
    // B B_solution;
    // B_solution.reverseString(v_input);
    // cout << "Answer: ";
    // for(int i = 0; i < v_input.size(); i++){
    //     cout << v_input[i];
    // }
    // cout << "\n";

    // C C_solution;
    // C_solution.reverseString(v_input);


    return 0;
}


