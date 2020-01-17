#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> dp (41, make_pair(-1, -1));

pair<int, int> fib (int n){
    

    if(n == 0) {
        return make_pair(1, 0);
    }
    if(n == 1) {
        return dp[1] = make_pair(0, 1);
    }

    if(dp[n].first != -1) return dp[n];
    dp[n].first = fib(n-1).first + fib(n-2).first;
    dp[n].second = fib(n-1).second + fib(n-2).second;

    return dp[n];
}

int main (){
    int T;
    cin >> T;

    while(T--){
        int n; cin >> n;
        pair<int, int> f = fib(n); 
        cout << f.first << " " << f.second << "\n";
    }
    return 0;
}