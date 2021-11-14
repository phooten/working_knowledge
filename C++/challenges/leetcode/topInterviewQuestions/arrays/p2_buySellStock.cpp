/*
    Date:       11-5-2021
    Status:     
    Source:     https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/564/

    Overview:
        You are given an integer array prices where prices[i] is the price of a 
        given stock on the ith day.

        On each day, you may decide to buy and/or sell the stock. You can only 
        hold at most one share of the stock at any time. However, you can buy it 
        then immediately sell it on the same day.

        Find and return the maximum profit you can achieve.
*/

#include <iostream> 
#include <vector>
using namespace std;


// Declartions
void printVector(vector<int>& vec);
int solution_A(vector<int>& vec);

int calculate_B(vector<int>& prices_cp, int s);
int solution_B(vector<int>& prices);

int calculate_leetcode(vector<int>& vec, int s);
int solution_leetcode(vector<int>& vec);


int main(){
    // Input
    const int days = 6;
    int prices[days] = {7,1,5,3,6,4}; // 6
    // int prices[days] = {1,2,3,4,5}; // 5
    // int prices[days] = {7,6,4,3,1}; // 5
    
    vector<int> prices_vec;
    for(int i = 0; i < days; i++){
        prices_vec.push_back(prices[i]);
    }


    printf("Pre\n");
    printVector(prices_vec);

    // int k = solution_A(prices_vec); 
    int k = solution_B(prices_vec); 
    // int k = solution_leetcode(prices_vec); 
    
    cout << "answser: " << k << "\n";
    // printf("\nPost\n");
    // printVector(prices_vec);
    
    

    return 0;
}


/*

*/
int solution_A(vector<int>& vec){
    // Vairables
    bool isDecending = true;
    int index = 0;
    int diff;
    int tmpProfit = 0;
    int maxProfit = 0; 
    
    // Initial 
    cout << "\n";
    int i = 0;
    int j = 1;
    bool solved = false;
    while(!solved){
        diff = vec[j] - vec[i]; 
        cout << "vec[" << j << "] - vec[" << i << "] = " << diff << "\n";
        if(diff > 0){
            tmpProfit += diff;
            i = j;
            j = i + 1;
        } else {
            j++;
        }

        if(tmpProfit > maxProfit){
            maxProfit = tmpProfit;
        }
        tmpProfit = 0;

        if(i == vec.size() - 1 || j == vec.size() - 1){
            solved = true;
        }
    }


    return maxProfit;
}
// ______________________________________________________________________________
int solution_B(vector<int>& prices) {
    return calculate_B(prices, 0);
}
int calculate_B(vector<int>& prices_cp, int s){
    int strtProfit = 0;
    int diffProfit = 0;
    int maxProfit = 0;
    
    if(prices_cp.size() == 0)
        return 0;
    
    for(int start = s; start < prices_cp.size(); start++){
        for(int i = start + 1; i < prices_cp.size(); i++){
            if(prices_cp[i] > prices_cp[start]){
                diffProfit = prices_cp[i] - prices_cp[start] + calculate_B(prices_cp, i);
                if(diffProfit > strtProfit)
                    strtProfit = diffProfit;
            }
        }
        
        if(strtProfit > maxProfit)
            maxProfit = strtProfit;
        
        strtProfit = 0;
    }       
    
    return maxProfit;
}

// ______________________________________________________________________________

/*
*/
// ______________________________________________________________________________
int solution_leetcode(vector<int>& vec){
    return calculate_leetcode(vec, 0);
}

int calculate_leetcode(vector<int>& vec, int s){
    // if(s >= vec.size())
    //     return 0;

    int max = 0;
    
    for(int start = s; start < vec.size(); start++){
        // cout << "start: " << start << "\n";
        int maxProfit = 0;
        for(int i = start + 1; i < vec.size(); i++){
            // cout << "start: " << start << "\n";
            if(vec[start] < vec[i]){
                // cout << "caclulate" << "\n";
                int profit = calculate_leetcode(vec, i + 1) + vec[i] - vec[start];
                if(profit > maxProfit)
                    maxProfit = profit;
            }
        }
        if(maxProfit > max)
            max = maxProfit;
    }

    return max;
}
// ______________________________________________________________________________

/*

*/
void printVector(vector<int>& vec){

    for(int i = 0; i < vec.size(); i++){
        printf("%d, ", vec[i]);
    }
    printf("\n");
    return;
}
