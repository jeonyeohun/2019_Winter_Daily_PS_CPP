#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int maxSquare;
        for (maxSquare = 1; maxSquare * maxSquare <= i;maxSquare++) {
            dp[i] = min(dp[i], dp[i - maxSquare * maxSquare] + 1);
        }
    }
    cout << dp[n];
}
