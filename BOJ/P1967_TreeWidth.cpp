#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10001] = { 0, };
int maxWidth = 0;
int maxVertex = 0;

void dfs(int start, vector<vector<pair<int, int>>>& adj, int cost) {
    visited[start] = true;

    for (auto next : adj[start]) {
        int nextVertex = next.first;
        int nextCost = next.second;
        if (!visited[nextVertex]) {
            dfs(nextVertex, adj, cost + nextCost);
        }
    }

    if (maxWidth < cost) {
        maxVertex = start;
        maxWidth = cost;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    dfs(1, adj, 0);

    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    dfs(maxVertex, adj, 0);

    cout << maxWidth;
}