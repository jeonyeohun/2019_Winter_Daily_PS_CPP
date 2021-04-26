#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int start = 0;
    int end = 0;
    int sum = 0;
    int cnt = 0;
    while (true) {

        if (sum >= M) {
            sum -= numbers[start];
            start++;
        }
        else if (end == N) break;
        else {
            sum += numbers[end];
            end++;
        }
        if (sum == M) cnt++;
    }

    cout << cnt;

}
