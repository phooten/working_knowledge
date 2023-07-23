#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int c_profit = 0; // current


        // Alorithm 1: buy and sell as soon as you can
        auto curr = prices.begin();
        bool found = false;
        while( curr < prices.end() )
        {
            found = false;
            for( auto next=curr+1; next <= prices.end(); next++ )
            {
                if( *curr < *next )
                {
                    c_profit += *next - *curr;
                    //cout << "curr: " << *curr << "  < next: " << *next << "  diff == " << *next - *curr << endl;
                    curr = next;
                    found = true;
                    break;
                }
            }

            if( found == false )
            {
                curr++;
            }
        }

        return c_profit;
    }
};

int main()
{
    Solution test;
    //int prices[] = {1,2,3,4,5};   // 4
    //int prices[] = {7,6,4,3,1};   // 0
    int prices[] = {7,1,5,3,6,4}; // 7


    
    int len = sizeof(prices) / sizeof(prices[0]);
    vector<int> vect;

    for( int i = 0; i < len; i++ )
    {
        vect.push_back( prices[i] );
        //cout << arr[x][y] << endl;
    }

    int ans = test.maxProfit(vect);
    cout << endl << endl << "answer: " << ans << endl;
}
