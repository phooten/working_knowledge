#include <string>
#include <iostream>
#include "hashTable.h"

using namespace std;

// Global Variables 
int ts = 100;
string initString = "empty";


/*
    Purpose:    Default Constructor
*/
Hash::Hash() {
    for(int i = 0; i < tableSize; i++){
        hashTable[i] = new Item;
        hashTable[i]->name = initString;
        hashTable[i]->drink = initString;
        hashTable[i]->next = NULL;
    }
}

/*
    Purpose:    Creates a key to a corrosponding spot in the hash table   

    Arguments:  key -   the name which needs a hash created for
    
    Return:     the index for the hash created
*/
int Hash::PreHash(string key){
    // Variables
    int hash = 0;
    int bucket;     // index

    for(int i = 0; i < key.length(); i++){
        hash += (int)key[i];
        // std::cout << "hash = " << hash << std::endl;
    }
    
    bucket = hash % tableSize;

    return bucket;
}

/*
    Purpose:    Adds an item in a linked list if there is more than one item in the bucket
    
    Arguments:  name -  The name to be added to the table
                drink - the component to add associated with the name
*/
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

/*
    Purpose:    Counts the total about of items stored in the linked list of the bucket
    Arguments:  bucket -   
    Return:      
*/
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


/*
    Purpose:  print out contents of the hashtable       
*/
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

/*
    Purpose:          
*/
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