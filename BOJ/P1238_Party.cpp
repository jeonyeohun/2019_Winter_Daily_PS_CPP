#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

void dijkstra(int start, vector<vector<pair<int, int>>>& towns, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        int here = pq.top().first;
        int hereCost = pq.top().second;
        pq.pop();

        if (dist[here] < hereCost) continue;

        for (auto next : towns[here]) {
            int there = next.first;
            int thereCost = hereCost + next.second;

            if (dist[there] > thereCost) {
                dist[there] = thereCost;
                pq.push({ there, thereCost });
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    vector<vector<pair<int, int>>> wayToward(1001);
    vector<vector<pair<int, int>>> wayBack(1001);
    vector<int> distBack(1001, INT_MAX);
    vector<int> distToward(1001, INT_MAX);

    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int here, there, cost;
        cin >> here >> there >> cost;

        wayToward[here].push_back({ there, cost });
        wayBack[there].push_back({ here, cost });
    }

    dijkstra(X, wayToward, distToward);
    dijkstra(X, wayBack, distBack);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(distToward[i] + distBack[i], ans);
    }

    cout << ans;


}
