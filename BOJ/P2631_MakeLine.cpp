#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> kids;
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        kids.push_back(n);
    }

    int lis = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] == 0) dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (kids[j] < kids[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                lis = max(lis, dp[i]);
            }
        }
    }

    cout << N - lis;

}
