#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6, 6, 7, 7, 7};
    // int len = sizeof(arr) / sizeof(arr[0]);
    int len = *(&arr + 1) - arr;
    cout << "\n" << *(&arr + 1) - arr << "\n";

    // Print array
    for(int i = 0; i < len; i++){
        cout << arr[i] << ", ";
    }
    cout << "\n";


    // Delete the repeating
    int index = 1;

    for(int i = 1; i < len; i++){
        if(arr[i] > arr[i - 1]){
            arr[index++] = arr[i];
        }
    }

    for(int i = index; i < len; i++){
        arr[i] = '\0';
    }

    int* newArr = new int[index];
    int newLen = index;
    for(int i = 0; i < index; i++){
        newArr[i] = arr[i];
    }


    // Print array
    for(int i = 0; i < newLen; i++){
        cout << newArr[i] << ", ";
    }
    cout << "\n";

    return 0;
}