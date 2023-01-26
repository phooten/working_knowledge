#include <iostream>
using namespace std;

void changeArr(int *arr, int size);

int main(){
    int arr[5] = { 1, 2, 3, 4, 5 };
    const int size = sizeof(arr) / sizeof(arr[0]);
    
    int *ptr_a = arr;
    int *ptr_b = &arr[0];
    int (*ptr_c)[size] = &arr;

    cout << "ptr_a: " << ptr_a << "\tptr_b: " << ptr_b << "\t&arr[0]: " << &arr[0] << "\n";
    
    changeArr(arr, size);
    return 0;
}

void changeArr(int *arr, int size){
    // cout << "changeArr():\n";
    // cout << "*arr: " << *arr << "\t\t&arr: " << &arr << "\tarr: " << arr << "\n";
    // *arr = 0;
    // cout << "*arr: " << *arr << "\t\t&arr: " << &arr << "\tarr: " << arr << "\n";
    // arr++;
    // *arr = 0;
    // cout << "*arr: " << *arr << "\t\t&arr: " << &arr << "\tarr: " << arr << "\n";
    
    return;
}