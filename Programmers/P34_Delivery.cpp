#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

void dijkstra(int N, vector<vector<pair<int, int>>>& adj, vector<int>& dists, vector<bool>& visited) {
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int hereVertex = pq.top().second;
        int hereCost = -pq.top().first;

        visited[hereVertex] = true;
        pq.pop();

        for (auto next : adj[hereVertex]) {
            int nextVertex = next.second;
            int nextCost = next.first;

            if (!visited[nextVertex] && dists[nextVertex] > hereCost + nextCost) {
                dists[nextVertex] = hereCost + nextCost;
                pq.push({ -dists[nextVertex], nextVertex });
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<int> dists(N + 1);
    vector<bool> visited(N + 1);

    for (int i = 2; i < dists.size(); i++) {
        dists[i] = INT_MAX;
    }

    for (auto path : road) {
        adj[path[0]].push_back({ path[2], path[1] });
        adj[path[1]].push_back({ path[2], path[0] });
    }

    dijkstra(N, adj, dists, visited);

    for (int i = 1; i < dists.size(); i++) {
        if (dists[i] <= K) answer++;
    }

    return answer;
}