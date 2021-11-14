/*
    Date:   11-6-2021
    Source: https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
    Overview:
        This problem was easier for higher time complexities, but what they 
        are trying to make you achieve makes it pretty difficult. I couldn't
        understand pas ~O(p) where p is unique factors, i.e. 2, 3, 5, 7, etc.
*/

#include <iostream> 
#include <vector>
#include <math.h>
using namespace std;


/*
    First attempt:
        This is a brute force method, but can be simplified by skipping multiples. 
        see class B
        -   17/66 cases passed
            -   Time limit exceeded on 499979

*/
class A{
public:
    A(){}

    bool isPrime(int n, int start){
        int factors = 2;

        if(n == 2)
            return true;
        
        for(int i = 2; i < n - 1; i++){
            if(n % i == 0)
                return false;
        }

        return true;
    }

    int countPrimes(int n){
        int amountPrimes = 0;
        // 3, 5, 7, 11, 13, 17, 19, 
        // Prime - 1, itself

        // count how many primes
        
        for(int num = 2; num < n; num++){
            if(isPrime(num, 2))
                amountPrimes++;
        }

        
        return amountPrimes;
    }
};

/*
    Second attempt:
        Tried to understand the solution, and got ~O(n^2) reduced slightly. 
        Still not up to time constraints though. 
*/
class B{
public:
    B(){}

    bool isPrime(int curr, int n){     
        if(curr > 10){
            // Checks for multiples of 2, 3, and 5
            if(curr % 2 == 0 || curr % 3 == 0 || curr % 5 == 0)
                return false;
            
            for(int i = curr; i < sqrt(n) + 1; i + curr){
                if(curr % i == 0)
                    return false;
            }

        } else {
            if(curr == 2){
                return true;

            } else {

                for(int i = 2; i < curr; i++){
                    if(curr % i == 0){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    int countPrimes(int n){
        int amountPrimes = 0;

        // 3, 5, 7, 11, 13, 17, 19, 
        // Prime - 1, itself

        // count how many primes
        for(int curr = 2; curr < n; curr++){
            if(isPrime(curr, n)){
                amountPrimes++;
            } 
        }

        
        return amountPrimes;
    }
};



int main(){
    // int n = 0;
    // int n = 1;
    int n = 10;

    A A_solution;
    B B_solution;

    int ans = B_solution.countPrimes(n);
    // cout << "Number of Primes: " << A_solution.countPrimes(n) << "\n";
    cout << "Number of Primes: " << ans << "\n";

    return 0;
}
