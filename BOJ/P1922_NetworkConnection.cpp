#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];
int level[1001];

int findRoot(int x) {
    if (parent[x] == x) return x;
    else return findRoot(parent[x]);
}

bool merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return false;

    if (level[a] > level[b]) swap(a, b);
    parent[a] = b;

    if (level[a] == level[b]) level[b]++;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M;

    cin >> N >> M;
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({ c, {a, b} });
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    for (auto edge : edges) {
        if (merge(edge.second.first, edge.second.second)) {
            cost += edge.first;
        }
    }

    cout << cost;
}