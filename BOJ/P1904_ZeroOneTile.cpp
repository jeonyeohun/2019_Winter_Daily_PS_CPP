#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp (10000001, -1);

long long getComb (long long n){
    if (n <=2) return n;
    
    if (dp[n] != -1) return dp[n];
    
    return dp[n] = getComb(n-1)%15746 + getComb(n-2)%15746;
    
    return dp[n];
}

int main (){
    long long N;
    cin >> N;

    getComb(N);

    cout << dp[N]%15746 << endl;
}
