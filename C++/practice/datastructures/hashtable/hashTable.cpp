#include <string>
#include <iostream>
#include "hashTable.h"

using namespace std;

int ts = 100;
string initString = "empty";


// Default Constructor
Hash::Hash() {
    for(int i = 0; i < tableSize; i++){
        hashTable[i] = new Item;
        hashTable[i]->name = initString;
        hashTable[i]->drink = initString;
        hashTable[i]->next = NULL;
    }
}

// Constructor
// Hash::Hash(string key) {}

// Creates a key to a corrosponding spot in the hash table
int Hash::PreHash(string key){
    // Variables
    int hash = 0;
    int bucket;     // index

    //
    for(int i = 0; i < key.length(); i++){
        hash += (int)key[i];
        // std::cout << "hash = " << hash << std::endl;
    }
    
    bucket = hash % tableSize;

    return bucket;
}

// Adds an item in a linked list if there is more than one item in the bucket
void Hash::AddItem(string name, string drink){
    int bucket = PreHash(name);     // index

    if(hashTable[bucket]->name == initString){  // if blank
        hashTable[bucket]->name = name;
        hashTable[bucket]->drink = drink;
    } else {
        Item *ptr = hashTable[bucket];
        Item *n = new Item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = n;
        
    }
}

// Counts the total about of items stored in the linked list of the bucket
int Hash::IndexCount(int bucket){
    // Variables
    int count = 0;
    
    if(hashTable[bucket]->name == initString){
        return count;
    } else {
        count++;
        Item *ptr = hashTable[bucket];
        while(ptr->next != NULL){
            count++;
            ptr = ptr->next;
        }
    }
    
    PrintBucketList(bucket);

    return count;
}

void Hash::PrintTable(){
    // Variables
    int number;

    for(int i = 0; i < tableSize; i++){
        number = IndexCount(i);
        cout << "-------------------\n" ;
        cout << "index: " << i << endl;
        cout << "name: " << hashTable[i]->name << endl;
        cout << "drink: " << hashTable[i]->drink << endl;
        cout << "# of items: " << number << endl;
        cout << "-------------------\n" ;
    }

    cout << endl << "-----------------END-----------------" << endl;
    return;
}

void Hash::PrintBucketList(int bucket){
    Item *ptr = hashTable[bucket];

    if(ptr->name == initString){
        cout << "bucket: " << bucket << " is empty" << endl;
    } else {
        cout << "bucket: " << bucket << " contains: " << endl;
        while(ptr != NULL){
            cout << "-------------------\n";
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "-------------------\n";
            ptr = ptr->next;
        }
    }
}