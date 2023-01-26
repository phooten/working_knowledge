/*
    Given an array of size n containing equal number of odd and even numbers. 
    The problem is to arrange the numbers in such a way that all the even numbers 
    get the even index and odd numbers get the odd index. Required auxiliary 
    space is O(1).
    
    https://www.geeksforgeeks.org/even-numbers-even-index-odd-numbers-odd-index/

*/

#include <iostream>
using namespace std;

class Solution_a{
public:
    Solution_a(){}

    void sortEvenOdd(int *arr, int size){
        int even = 0;
        int odd = 1;
        int tmp;
        while(true){
            while(even < size && arr[even] % 2 == 0)
                even += 2;
            
            while(odd < size && arr[odd] % 2 == 1)
                odd += 2;

            if(even < size && odd < size){
                tmp = arr[even];
                arr[even] = arr[odd];
                arr[odd] = tmp;
            } else{
                break;
            }
        }
        return;
    }

};


void printArr(int *arr, int size);


int main(){
    // int arr[] = {3, 6, 12, 1, 5, 8};
    int arr[] = {10, 9, 7, 18, 13, 19, 4, 20, 21, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original Array:\n";
    printArr(arr, size);
    
    Solution_a a;
    a.sortEvenOdd(arr, size);

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

