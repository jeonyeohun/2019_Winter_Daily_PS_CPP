#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, INT_MAX);

    for (auto e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    priority_queue<int, vector<int>> pq;
    pq.push(1);
    dist[1] = 0;

    int maxDist = 0;
    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();

        for (auto next : adj[now]) {
            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                pq.push(next);
            }
        }
    }

    sort(dist.begin(), dist.end());

    while (dist.back() == INT_MAX) {
        dist.pop_back();
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == dist.back()) {
            answer++;
        }
    }

    return answer;
}