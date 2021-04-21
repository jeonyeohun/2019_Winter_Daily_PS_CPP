#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;
vector<int> level;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int findRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findRoot(parent[x]);
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

int solution(int n, vector<vector<int>> costs) {
    parent.resize(n + 1);
    level.resize(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    sort(costs.begin(), costs.end(), cmp);

    int sum = 0;
    for (auto cost : costs) {
        if (merge(cost[0], cost[1])) {
            sum += cost[2];
        }
    }

    return sum;
}