#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp(N, 0);
    vector<int> nums(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    dp[0] = nums[0];           // 바로 처음 포도주를 마실 때
    dp[1] = nums[0] + nums[1]; // 1번, 2번 포도주를 연달아 마실 때

    for (int i = 2; i < N; i++)
    {
        // dp[i-1] : 이번 위치에서 안마시고 넘어갈때. 이전 값이 유지된다.
        // dp[i-2] + nums[i] : 이번 위치에서 마시고 이전 위치에서 안마실 때.
        // dp[i-3] + nums[i] + nums[i-1] : 두 번 연달아 마실 때
        dp[i] = max(dp[i - 1], (max(dp[i - 2] + nums[i], dp[i - 3] + nums[i] + nums[i - 1])));
    }

    cout << dp[N - 1];
    return 0;
}