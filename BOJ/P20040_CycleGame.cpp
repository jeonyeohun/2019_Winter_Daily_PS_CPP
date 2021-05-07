#include <iostream>
#include <algorithm>

using namespace std;

int parent[500000];
int level[500000];

int findRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findRoot(parent[x]);
}

bool merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return true;

    if (level[a] > level[b]) {
        swap(a, b);
    }
    if (level[a] == level[b]) level[b]++;

    parent[a] = b;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, answer = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        level[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (merge(a, b)) {
            answer = i;
            break;
        }
    }

    cout << answer;

}