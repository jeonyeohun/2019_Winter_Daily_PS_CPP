#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> plates(N + k);
    vector<int> typeCount(d + 1, 0);
    int start = 0, end = k - 1, count = 0;
    int maxCount = 0;

    for (int i = 0; i < N; i++) {
        cin >> plates[i];
        if (i < k) {
            typeCount[plates[i]]++;
            if (typeCount[plates[i]] == 1) count++;
        }
    }

    for (int i = 1; i < N; i++) {
        if (maxCount <= count) {
            maxCount = typeCount[c] == 0 ? count + 1 : count;
        }

        typeCount[plates[i - 1]]--;
        if (typeCount[plates[i - 1]] == 0) count--;

        if (typeCount[plates[(i + k - 1) % N]] == 0) count++;
        typeCount[plates[(i + k - 1) % N]]++;
    }


    cout << maxCount;
}
