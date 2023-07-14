#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int other = 0;
        char tmp;
        for( auto curr = 0; curr < len / 2; curr++ )
        {
            other = len - curr - 1;
            //std::cout << "other: " << other;
            tmp = s[other];
            s[other] = s[curr];
            s[curr] = tmp;
        }
    }
};

int main()
{
    Solution test;
    char arr[] = {'H', 'E', 'L', 'L', 'O' };

    int len = sizeof(arr) / sizeof(arr[0]);
    vector<char> vect;

    for( int i = 0; i < len; i++ )
    {
        vect.push_back( arr[i] );
        //cout << arr[x][y] << endl;
    }
    for( auto i = vect.begin(); i < vect.end(); i++ )
    {
        cout << *i;
    }

    cout << endl << endl;

    test.reverseString(vect);
    for( auto i = vect.begin(); i < vect.end(); i++ )
    {
        cout << *i;
    }

    //cout << endl << endl << "answer: " << vect << endl;
}
