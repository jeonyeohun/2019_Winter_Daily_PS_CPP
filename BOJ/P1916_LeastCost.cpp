#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int dist[1001];
bool visited[1001];
vector<vector<pair<int, int>>> cities(1001);

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

int dijkstra(int start, int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        int costHere = pq.top().second;
        int here = pq.top().first;
        pq.pop();

        if (dist[here] < costHere) continue;

        for (auto next : cities[here]) {
            int costThere = costHere + next.second;
            int there = next.first;

            if (costThere < dist[there]) {
                dist[there] = costThere;

                pq.push({ there, costThere });
            }
        }
    }



    return dist[dest];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < M; i++) {
        int here, there, cost;
        cin >> here >> there >> cost;

        cities[here].push_back({ there, cost });
    }

    int start, dest;
    cin >> start >> dest;

    cout << dijkstra(start, dest) << endl;
}