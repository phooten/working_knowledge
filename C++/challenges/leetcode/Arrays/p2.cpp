#include <iostream> 
#include <vector>
using namespace std;


// Declartions
void printVector(vector<int>& vec);
int solution_A(vector<int>& vec);
int calculate(vector<int>& vec, int s);
int solution_leetcode(vector<int>& vec);


int main(){
    // Input
    const int days = 6;
    int prices[days] = {7,1,5,3,6,4}; // 6
    // int prices[days] = {1,2,3,4,5}; // 5
    // int prices[days] = {7,6,4,3,1}; // 5
    int len = sizeof(prices[days])/sizeof(prices[days]);
    
    vector<int> prices_vec;
    for(int i = 0; i < days; i++){
        prices_vec.push_back(prices[i]);
    }


    printf("Pre\n");
    printVector(prices_vec);

    int k = solution_leetcode(prices_vec); 
    
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


/*

*/
int solution_leetcode(vector<int>& vec){
    return calculate(vec, 0);
}


/*

*/
int calculate(vector<int>& vec, int s){
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
                int profit = calculate(vec, i + 1) + vec[i] - vec[start];
                if(profit > maxProfit)
                    maxProfit = profit;
            }
        }
        if(maxProfit > max)
            max = maxProfit;
    }

    return max;
}

/*

*/
void printVector(vector<int>& vec){

    for(int i = 0; i < vec.size(); i++){
        printf("%d, ", vec[i]);
    }
    printf("\n");
    return;
}
