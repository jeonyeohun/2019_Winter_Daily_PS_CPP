#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;
    deque<pair<int, int>> dq;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        dq.push_back({ n, i });
    }

    while (!dq.empty()) {
        auto next = dq.front();
        dq.pop_front();

        cout << next.second << " ";

        if (next.first > 0) {
            for (int i = 0; i < next.first - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            next.first *= -1;
            for (int i = 0; i < next.first; i++) {
                dq.push_front(dq.back());
                dq.pop_back();

            }
        }
    }
}
