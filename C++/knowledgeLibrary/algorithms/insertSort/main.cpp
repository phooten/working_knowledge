#include <iostream>
#include <time.h>

#define DEFAULT_LENGTH 100
#define DEFAULT_MAX 10000

int randomArray(int* arr, int n=DEFAULT_LENGTH, int r=DEFAULT_MAX);


int main(){
    int* inputPtr;
    int inputLen = randomArray(inputPtr, 10);

    for(int i = 0; i < inputLen; i++){
        std::cout << inputPtr[i] << ", ";
    }
    printf("\n");

    // clean up
    delete(inputPtr);

    return 0;
}



int randomArray(int* arr, int n, int r){
    arr = new int[n];      // Gets deleted in main 
    int randNum;
    
    for(int i = 0; i < n; i++){
        randNum = rand() % r;
        arr[i] = randNum; 
    }

    return n;
}