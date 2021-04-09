#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    int sum[N + 1];
    int nums[N + 1];

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        sum[i] = sum[i - 1] + nums[i];
    }

    for (int i = 0; i < M; i++) {
        int left, right;
        cin >> left >> right;
        cout << sum[right] - sum[left - 1] << "\n";
    }

}