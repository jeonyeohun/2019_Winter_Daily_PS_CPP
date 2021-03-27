#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int parent[100001];
int level[100001];

int calcCost(int a, int b) {
    return abs(a - b);
}

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

    int N;
    cin >> N;

    vector<pair<int, int>> xCord;
    vector<pair<int, int>> yCord;
    vector<pair<int, int>> zCord;

    for (int idx = 0; idx < N; idx++) {
        int x, y, z;
        cin >> x >> y >> z;
        xCord.push_back({ x, idx });
        yCord.push_back({ y, idx });
        zCord.push_back({ z, idx });
    }

    sort(xCord.begin(), xCord.end());
    sort(yCord.begin(), yCord.end());
    sort(zCord.begin(), zCord.end());

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < N - 1; i++) {
        edges.push_back({ calcCost(xCord[i].first, xCord[i + 1].first), {xCord[i].second, xCord[i + 1].second} });
        edges.push_back({ calcCost(yCord[i].first, yCord[i + 1].first), {yCord[i].second, yCord[i + 1].second} });
        edges.push_back({ calcCost(zCord[i].first, zCord[i + 1].first), {zCord[i].second, zCord[i + 1].second} });
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    for (auto edge : edges) {
        int firstVertex = edge.second.first;
        int secondVertex = edge.second.second;
        int cost = edge.first;

        if (!merge(firstVertex, secondVertex)) {
            totalCost += cost;
        }
    }

    cout << totalCost;
}