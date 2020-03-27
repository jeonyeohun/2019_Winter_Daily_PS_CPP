#include <iostream>

using namespace std;

typedef long long ll;

ll dp[91][2]{{0, 0}};

int main()
{
    int n;

    dp[1][1] = 1;

    for (int i = 2; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n];
}