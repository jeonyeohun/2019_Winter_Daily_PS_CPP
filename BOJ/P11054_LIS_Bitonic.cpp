#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> dp(N, make_pair(1, 1));
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    // 왼쪽 수열 최대 길이
    for (int i = 1; i < N; i++)
    {
        int maxLen = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                maxLen = max(maxLen, dp[j].first);
            }
        }
        dp[i].first = maxLen + 1;
    }

    // 오른쪽 수열 최대 길이
    for (int i = N - 2; i >= 0; i--)
    {
        int maxLen = 0;
        for (int j = N - 1; j > i; j--)
        {
            if (nums[i] > nums[j])
            {
                maxLen = max(maxLen, dp[j].second);
            }
        }
        dp[i].second = maxLen + 1;
    }

    int ans = 0;
    for (auto i : dp)
    {
        ans = max(ans, i.first + i.second);
    }

    cout << ans - 1 << endl;
    return 0;
}