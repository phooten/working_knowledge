/*
    Date:           9-10-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   koffe-byte                    
                    Paul Programming (see Credits)

    Purpose:        To learn and understand Hash tables. This is a simple 
                    program to store values in this kind of data structure.  

    sample input:
                    string arrays inside main 

    Questions to think about:
        1. What is a hash table's time/space complexity? Specifically for search
            add, remove, sort?

    Credits:
        Paul Programming:
            -   This code was written while watching this youtube channel. Pieces 
                of this program reference following link. It with the purposes 
                of learning about hashtables, and better programming practice.
                Link:  https://www.youtube.com/watch?v=oj6YWN4W-jk&list=PLTxllHdfUq4f7-uHOpxXnBUbsuLiI9pmb&index=12
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "hashTable.h"
using namespace std;

// Controls operation of the program.
int main(int argc, char** argv){
    // Variables  
    int size = 11;
    string name[size] = {"Sara", "Tyler", "Josh", "Chloe", "Joe", "Matt", "Terry", "Adrian", "Adrian", "Tanjiro", "Channing"};
    string drink[size] = {"Coffee", "Coke", "Water", "Latte", "Budlight", "Vizzy", "Milk", "Tea", "Tea", "Sake", "Protein Shake"};

    
    // Testing:
    Hash a;
    
    for(int i = 0; i < size; i++)
        a.AddItem(name[i], drink[i]);

    a.PrintTable();
    
	return 0;
}


