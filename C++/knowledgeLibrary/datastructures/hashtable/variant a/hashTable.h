#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
using namespace std;


class Hash{
    public:
        Hash();
        // Hash(string key);
        
        int PreHash(string key);        // Maps Key to non neg int
        void AddItem(string name, string drink);
        int IndexCount(int bucket);     // Number of items in the index
        void PrintTable();
        void PrintBucketList(int bucket);

    private:
        static const int tableSize = 10;

        struct Item{
            string name;
            string drink;
            Item *next;
        };

        Item *hashTable[tableSize];

};

#endif // HASHTABLE_H