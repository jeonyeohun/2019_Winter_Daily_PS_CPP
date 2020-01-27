#include <iostream>
#include <algorithm>
 
using namespace std;
 
int dp[1001][3];
int main() {
    int num, r, g, b;
    cin >> num;
    for(int i = 1; i <= num; i++) {
        cin >> r >> g >> b;
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b;
    }
    cout << min(dp[num][0], min(dp[num][1], dp[num][2]));
 
    return 0;
}
