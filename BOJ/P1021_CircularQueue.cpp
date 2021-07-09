#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> dq;
    deque<int> targets;
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        targets.push_back(num);
    }

    int opCount = 0;
    while (!targets.empty()) {
        if (dq.front() == targets.front()) {
            targets.pop_front();
            dq.pop_front();
            continue;
        }

        int targetIndex = find(dq.begin(), dq.end(), targets.front()) - dq.begin();

        if (targetIndex > dq.size() / 2) {
            dq.push_front(dq.back());
            dq.pop_back();
            opCount++;
        }
        else if (targetIndex <= dq.size() / 2) {
            dq.push_back(dq.front());
            dq.pop_front();
            opCount++;
        }
    }

    cout << opCount;
}
