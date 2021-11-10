/*

    https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

*/

#include <iostream>
using namespace std;

class Solution{
public:
    Solution(){}

    void sum_a(int *arr, int size, int k){
        int min, max;
        int relSum = 0;
        int sum = 0;
        for(int i = 0; i < size - k; i++){
            min = arr[i];
            max = arr[i];
            for(int j = i; j < k; j++){
                if(arr[j] < min)
                    min = arr[j];
                
                if(arr[j] > max)
                    max = arr[j];
            }
            relSum = min + max;
            sum += relSum;
        }

        cout << "sum: " << sum << "\n";
    }


};


void printArr(int *arr, int size);


int main(){
    // int arr[] = {3, 6, 12, 1, 5, 8};
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "Original Array:\n";
    printArr(arr, size);
    
    Solution ans;
    // ans.sum_a(arr, size, k);

    cout << "Sorted Array:\n";
    printArr(arr, size);


    return 0;
}


void printArr(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1];

    cout << "\n\n";
}

