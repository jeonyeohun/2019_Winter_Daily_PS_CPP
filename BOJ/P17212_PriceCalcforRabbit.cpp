#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100002];

int main()
{
    int N;
    scanf("%d", &N);

    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (i % 7 == 0)
            dp[i] = i / 7;
        if (i == 2 || i == 5 || i == 7)
            dp[i] = 1;
        else
        {
            dp[i] = min(dp[i - 1] + 1, dp[i - 2] + 1);
            if (i >= 5)
                dp[i] = min(dp[i], dp[i - 5] + 1);
            if (i >= 7)
                dp[i] = min(dp[i], dp[i - 7] + 1);
        }
    }
    /*
    for (int i = 1; i <= N; i++)
    {
        printf("%d : %d \n", i, dp[i]);
    }
*/
    printf("%d", dp[N]);
    return 0;
}