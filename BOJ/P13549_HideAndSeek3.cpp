#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int dist[100001];
int N, K;

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int next = pq.top().second;
        int costHere = pq.top().first;
        pq.pop();

        if (next < 100000 && dist[next + 1] > costHere + 1) {
            dist[next + 1] = costHere + 1;
            pq.push({ costHere + 1, next + 1 });
        }
        if (next > 0 && dist[next - 1] > costHere + 1) {
            dist[next - 1] = costHere + 1;
            pq.push({ costHere + 1, next - 1 });
        }
        if (next < 50001 && dist[next * 2] > costHere) {
            dist[next * 2] = costHere;
            pq.push({ costHere, next * 2 });
        }
    }
}

int main() {

    cin >> N >> K;

    for (int i = 0; i <= 100000; i++) {
        dist[i] = INT_MAX;
    }

    if (N == K) {
        cout << "0";
        return 0;
    }

    dijkstra(N);

    cout << dist[K];

}
