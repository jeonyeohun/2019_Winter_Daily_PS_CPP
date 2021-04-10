#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    int snows[601];
    for (int i = 0; i < N; i++) {
        cin >> snows[i];
    }

    sort(snows, snows + N);

    int minDiff = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int start = 0, end = N - 1;
            while (true) {
                if (start == i) {
                    start++;
                }
                if (start == j) {
                    start++;
                }
                if (end == j) {
                    end--;
                }
                if (end == i) {
                    end--;
                }

                if (start >= end) break;

                int firstPair = snows[i] + snows[j];
                int secondPair = snows[start] + snows[end];
                int diff = abs(firstPair - secondPair);

                minDiff = min(minDiff, diff);

                if (firstPair > secondPair) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
    }

    cout << minDiff;
}
