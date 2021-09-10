/**
    Overview: Description of the file
    @file main.cpp
    @author Parker Hooten
    @version 1.1 5/9/2021 [ D/M/Y ]
*/

// Helpful Video: https://www.youtube.com/watch?v=m6n_rozU8dA&list=PLTxllHdfUq4f7-uHOpxXnBUbsuLiI9pmb&index=2
// go to: part 11

#include <iostream>
#include <cstdlib>
#include <string>
#include "hashTable.h"
using namespace std;

// Controls operation of the program.
int main(int argc, char** argv){
    // Variables  

    
    // Personal Testing:

    int size = 11;
    string name[size] = {"Sara", "Tyler", "Josh", "Chloe", "Joe", "Matt", "Terry", "Adrian", "Adrian", "Tanjiro", "Channing"};
    string drink[size] = {"Coffee", "Coke", "Water", "Latte", "Budlight", "Vizzy", "Milk", "Tea", "Tea", "Sake", "Protein Shake"};
    
    Hash a;
    
    for(int i = 0; i < size; i++){
        a.AddItem(name[i], drink[i]);
    }

    a.PrintTable();
    
    // for(int i = 0; i < size; i++){
    //     cout << name[i] << " - preHash: " << a.PreHash(name[i]) << endl;
    // }
    

	return 0;
}


