#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int const MAX = 10001;

int dp[MAX];

int main()
{
    int n, k;
    vector<int> coins;

    scanf("%d %d", &n, &k);

    while (n--)
    {
        int coin;
        scanf("%d", &coin);
        coins.push_back(coin);
    }

    dp[0] = 1;
    for (auto coin : coins)
    {
        for (int i = coin; i <= k; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    printf("%d", dp[k]);
}
