#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main()
{
    int A[100001];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    dp[0] = A[0];
    int result = A[0];

    for (int i = 0; i < n; i++)
    {
        if (A[i - 1] < 0)
            dp[i] = max(A[i], A[i] + dp[i - 1]);
        else
            dp[i] = A[i] + dp[i - 1];

        result = max(result, dp[i]);
    }

    cout << result;
}