#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];
int level[100001];

int findRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findRoot(parent[x]);
}

bool merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return true;

    if (level[a] > level[b]) swap(a, b);

    parent[a] = b;

    if (level[a] == level[b]) level[b]++;

    return false;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({ c, {a, b} });
    }

    sort(edges.begin(), edges.end());

    int totalCost = 0;
    int maxCost = 0;
    for (auto edge : edges) {
        if (!merge(edge.second.first, edge.second.second)) {
            totalCost += edge.first;
            maxCost = max(maxCost, edge.first);
        }
    }

    cout << totalCost - maxCost;
}
