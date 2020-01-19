#include<iostream>
#include<vector>

using namespace std;

vector<long long> dp(102, -1);

long long p (int n){
    if (dp[n] != -1) return dp[n];
    
    return dp[n] = p(n-2) + p(n-3);
}

int main (){
    int N;
    cin >> N;

    for (int i = 1 ; i <= 3 ; i++) dp[i] = 1;

    while(N--){
        int t;
        cin >> t;
        p(t);
        cout << dp[t] << "\n"; 
    }

    return 0;
}