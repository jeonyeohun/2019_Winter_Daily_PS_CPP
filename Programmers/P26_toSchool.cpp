#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[101][101] = { 0, };

    for (auto puddle : puddles) {
        if (puddle.empty()) continue;
        dp[puddle[0]][puddle[1]] = -1;
    }

    dp[1][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == -1) dp[i][j] = 0;
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
        }
    }

    return dp[m][n];
}