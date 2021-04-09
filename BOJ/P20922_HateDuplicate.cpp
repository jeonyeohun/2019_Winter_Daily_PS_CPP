#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int nums[N + 1];

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int start = 0, end = 0;
    int visited[N + 1];

    int maxLen = 0;
    while (start <= end) {
        if (visited[end] < K) {
            end++;
            visited[end]++;
            maxLen = max(maxLen, end - start + 1);
        }
        else {
            visited[start]--;
            start++;
        }
    }

    cout << maxLen;
}