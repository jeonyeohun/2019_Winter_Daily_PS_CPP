#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> dp;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;

        if (dp.empty() || dp.back() < num) {
            dp.push_back(num);
        }
        else {
            dp[lower_bound(dp.begin(), dp.end(), num) - dp.begin()] = num;
        }
    }

    cout << dp.size();
}
