#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp(N);
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    dp[0] = 1; // 첫번째 숫자는 무조건 최장 부분 수열의 길이가 1이다. 숫자가 하나 밖에 없으니까..

    for (int i = 1; i < N; i++) // 두번째 숫자부터 끝까지 순회한다.
    {
        int longest = 0;            // 길이를 이 녀석을 가지고 계산할거임
        for (int j = 0; j < i; j++) // 증가하는 부분 수열이므로, 현재 기준이 되는 숫자의 이전에 나오는 값들만 확인하면 된다.
        {
            if (nums[i] > nums[j]) // 증가해야하므로, 현재 숫자보다 작은 녀석들이 나올 때만 진행
            {
                longest = max(longest, dp[j]); // 현재 숫자보다 작은 숫자가 가지는 가장 긴 증가하는 부분 수열의 값을 확인한다.
                // 기준이 되는 숫자보다 작은 숫자가 여러개 있을 수도 있으니까 그중에서 증가하는 부분수열 길이가 가장 긴 길이를 선택한다.
            }
        }
        dp[i] = 1 + longest; // 가장 길이가 길었던 값에서 1만 더해주면 현재 숫자까지의 가장 긴 증가하는 부분 수열의 길이가 나온다.
    }

    sort(dp.begin(), dp.end(), greater<int>()); // 가장 긴 길이가 중간에 있을 수도 있으니까, 제일 큰 값을 찾아서 출력하자.

    cout << dp[0];
}