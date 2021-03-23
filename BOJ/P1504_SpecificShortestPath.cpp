#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<long long> dist(801);
vector<vector<pair<int, int>>> edges(801);

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

vector<long long> dijkstra(int start) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        int here = pq.top().first;
        int hereCost = pq.top().second;
        pq.pop();

        for (auto next : edges[here]) {
            int there = next.first;
            int thereCost = next.second + hereCost;

            if (dist[there] > thereCost) {
                dist[there] = thereCost;
                pq.push({ there, thereCost });
            }
        }
    }

    return dist;
}

void clearDist(int N) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }

    int pointOne, pointTwo;

    cin >> pointOne >> pointTwo;

    clearDist(N);
    auto fromStartDist = dijkstra(1);

    clearDist(N);
    auto fromPointOneDist = dijkstra(pointOne);

    clearDist(N);
    auto fromPointTwoDist = dijkstra(pointTwo);

    long long pointOneFirst = fromStartDist[pointOne] + fromPointOneDist[pointTwo] + fromPointTwoDist[N];
    long long pointTwoFirst = fromStartDist[pointTwo] + fromPointTwoDist[pointOne] + fromPointOneDist[N];

    long long answer = min(pointOneFirst, pointTwoFirst);

    if (answer < INT_MAX) {
        cout << answer;
    }
    else {
        cout << -1;
    }
}
