#include <iostream>
#include <vector>

using namespace std;

vector<string> names;
vector<int> nums;

int binarySearch(int target, int N) {
    int head = 0;
    int tail = N;
    int idx = 0;
    while (head <= tail) {
        int mid = (head + tail) / 2;
        if (nums[mid] < target) {
            head = mid + 1;
        }
        else {
            idx = mid;
            tail = mid - 1;
        }
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    names.resize(N);
    nums.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> names[i] >> nums[i];
    }

    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;

        cout << names[binarySearch(target, N)] << "\n";
    }
}
