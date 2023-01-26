#include <iostream>
using namespace std;


int main(){
    int arr_a[10];
    int arr_b[10];
    
    
    // Initializing a and b
    for(int i : arr_a)
        i = -1; 

    for(int &i : arr_b)
        i = -1;
    
    // Printing out a
    cout << "\n\na (without '&'): " << endl;
    for(int i : arr_a)
        cout << i << ", ";
    cout << endl;
    for(int &i : arr_a)
        cout << i << ", ";


    // Printing out b
    cout << "\n\nb (without '&'): " << endl;
    for(int i : arr_b)
        cout << i << ", ";
    cout << endl;
    for(int &i : arr_b)
        cout << i << ", ";
    cout << endl;


    return 0;
}