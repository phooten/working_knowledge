#include <string>
#include "hashTable.h"

using namespace std;

int ts = 100;


// Default Constructor
Hash::Hash() {
    for(int i; i < tableSize; i++){
        hashTable[i] = new Item;
        hashTable[i]->name = "empty";
        hashTable[i]->drink = "empty";
        hashTable[i]->next = NULL;
    }

}

// Constructor
Hash::Hash(string key) {}

// Creates a key to a corrosponding spot in the hash table
int Hash::preHash(string key){
    int hash = 0;
    int bucket; 

    bucket = key.length();
    for(int i = 0; i < key.length(); i++){
        hash += (int)key[i];
    }
    
    bucket = hash % tableSize;

    return bucket;
}


