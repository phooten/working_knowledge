/*
    Given an array of size n containing equal number of odd and even numbers. 
    The problem is to arrange the numbers in such a way that all the even numbers 
    get the even index and odd numbers get the odd index. Required auxiliary 
    space is O(1).
    
    https://www.geeksforgeeks.org/even-numbers-even-index-odd-numbers-odd-index/

*/

#include <iostream>
using namespace std;

void sort(int arr[], int eIndex=0, int oIndex=1);
void printArr(int arr[]);

int main(){
    int arr[] = {3, 6, 12, 1, 5, 8};
    // int arr[] = {10, 9, 7, 18, 13, 19, 4, 20, 21, 14};
    sort(arr);
    


    return 0;
}

void sort(int arr[], int eIndex, int oIndex){
    int size = sizeof(arr) / sizeof(&arr[0]);
    cout << "size: " << size << "\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    cout << "\n";


    return;
}

void printArr(int arr[]){
    
}

