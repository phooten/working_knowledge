#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>
#include<cstring>
#include<locale>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Explaination: 
        //  Cycle through each string once, then count each letter occurnace.
        //  They should match, or else we know they can't be rearranged at all.
        //  There's an argument to be made if the anagram is an actual word, but
        //  that goes well past the scope of this simple challange.

        // Variables
        const int offset = 97;
        const int track_len = 26;
        bool ans = true;
        std::locale loc;

        // Immediatley known, so good to check first
        if( s.size() != t.size() )
        {
            return false;
        }

        // This significantly causes slower execution speed. It's not needed in
        // the use cases because non have capital letters. 
         for(auto elem : s)
            tolower(elem,loc);

         for(auto elem : t)
            tolower(elem,loc);


        // letters found go in an array
        int s_tracker[track_len] = {0};
        int t_tracker[track_len] = {0};


        // Extract letters from 1st string
        for( int curr = 0; curr < s.size(); curr++ )
        {
            if( s[curr] >= 'a' && s[curr] <= 'z' )
            {
                s_tracker[ (int)s[curr] - offset ] += 1;
            }
            else
            {
                cout << "Invalid character?";
                exit(1);
            }
        }

        // Extract letters from 2nd string
        for( int curr = 0; curr < t.size(); curr++ )
        {
            if( t[curr] >= 'a' && t[curr] <= 'z' )
            {
                t_tracker[ (int)t[curr] - offset ] += 1;
            }
            else
            {
                cout << "Invalid character?";
                exit(1);
            }
        }


        // Compare letter counts
        for( int letter = 0; letter < track_len; letter++ )
        {
            if( t_tracker[letter] != s_tracker[letter] )
            {
                return false;
            }
        }


        return ans;
    }
};

int main()
{
    string s1 = "anagram";
    string s2 = "nagaram";

    Solution test;
    cout << endl << endl;

    cout << "string 1: " << s1 << "\nstring 2: " << s2 << endl << endl << "These anagrams: " << ( test.isAnagram(s1, s2) ? "true" : "false" ) << endl << endl;

    //cout << endl << endl << "answer: " << vect << endl;
}
