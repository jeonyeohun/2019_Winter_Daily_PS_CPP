#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N, S, num;
    cin >> N >> S;
    int accNums[100001] = { 0, };

    for (int i = 1; i <= N; i++) {
        cin >> num;
        accNums[i] = accNums[i - 1] + num;
    }

    int start = 1, end = 1;
    int minLength = INT_MAX;
    while (end <= N) {
        if (accNums[end] - accNums[start - 1] >= S) {
            minLength = min(minLength, end - start + 1);
            ++start;
        }
        else {
            ++end;
        }
    }
    cout << (minLength == INT_MAX ? 0 : minLength);
}