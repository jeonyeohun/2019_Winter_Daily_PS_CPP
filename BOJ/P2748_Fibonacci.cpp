#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp (90);

int main (){
    dp[1] = 1;
    int n;
    cin >> n;

    for (int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-2]+dp[i-1];
    }

    cout << dp[n];
    return 0;
}