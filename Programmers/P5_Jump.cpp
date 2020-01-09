#include <string>
#include <vector>
#include <iostream>

using namespace std;

unsigned long long dp [2002] = {0, 1};

unsigned long long fib(int n){
    if (n < 2) return dp[n];
    for (int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1234567;
    }
    return dp[n];   
}

unsigned long long solution(int n) {
    unsigned long long answer = fib(n+1);
    return answer;
}