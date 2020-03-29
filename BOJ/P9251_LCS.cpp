#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main()
{
    string s1, s2;

    cin >> s1 >> s2;
    int lcs = 0;

    for (int i = 1; i <= s2.size(); i++)
    {
        for (int j = 1; j <= s1.size(); j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (s2[i - 1] == s1[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                lcs = max(lcs, dp[i][j]);
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << lcs;
    return 0;
}