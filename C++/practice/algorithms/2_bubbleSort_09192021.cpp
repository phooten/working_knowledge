/*
	Below is a template of a formatting structure I found on: 
		-> edparrish.net/common/cppdoc.html#curlybrace
*/

/**
    Overview: Description of the file
    @file main.cpp
    @author Parker Hooten
    @version 1.1 5/9/2021 [ D/M/Y ]
*/

/**
    Description of the function
	@param input the input into the function.
    @return what is being returned.

    The first loop will push the greatest value to the end, the next will push the greatest value to the end etc. 
*/

#include <cstdlib>
#include<iostream>
using namespace std;

int bubbleSort(int arr[], int len);
void printArr(int arr[], int len);

// Controls operation of the program.
int main(){
    // random array
    unsigned int length = 10;
    int arr[length];
    int i, rNum;

    for(i = 0; i < length; i++){
        rNum = rand() % 100;
        arr[i] = rNum;
    }

    printArr(arr, length);
    bubbleSort(arr, length);
    printArr(arr, length);

    return 0;
}

// Description of the function
int bubbleSort(int arr[], int len){
    int curr;
    int tmp;
    int i, j;

    for(i = 0; i < len; i++){
        for(j = 0; j < len - i; j++){
            curr = j;
            if(arr[curr] > arr[curr + 1]){
                tmp = arr[curr];
                arr[curr] = arr[curr + 1];
                arr[curr + 1] = tmp;    
            }
        }
    }

    return 0;
}

void printArr(int arr[], int len){
    int i, j;
    for(i = 0; i < len - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[i] << endl;

    return;
}
