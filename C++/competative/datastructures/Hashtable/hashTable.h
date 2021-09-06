#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
using namespace std;


class Hash{
    public:
        Hash();
        Hash(string key);
        
        int preHash(string key);    // Maps Key to non neg int

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