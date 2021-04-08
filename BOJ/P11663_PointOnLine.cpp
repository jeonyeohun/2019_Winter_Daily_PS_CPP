#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> points;

long long binarySearch(long long target, long long N, bool isStart) {
    long long head = 1;
    long long tail = N;
    long long mid = 0;

    if (!isStart) {
        while (head <= tail) {
            mid = (head + tail) / 2;
            if (points[mid] <= target) {
                head = mid + 1;
            }
            else {
                tail = mid - 1;
            }
        }
    }
    else {
        while (head <= tail) {
            mid = (head + tail) / 2;
            if (points[mid] >= target) {
                tail = mid - 1;

            }
            else {
                head = mid + 1;
            }
        }
    }

    return isStart ? head : tail;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;

    points.resize(N + 1);

    for (long long i = 1; i <= N; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    for (long long i = 0; i < M; i++) {
        long long start, end;

        cin >> start >> end;

        cout << binarySearch(end, N, false) << " " << binarySearch(start, N, true) << endl;
        cout << binarySearch(end, N, false) - binarySearch(start, N, true) + 1 << "\n";
    }
}