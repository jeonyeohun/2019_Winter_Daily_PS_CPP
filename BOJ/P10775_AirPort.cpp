#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1000001];

int findRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findRoot(parent[x]);
}

void merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    parent[a] = b;
}

int main() {
    int G, P;
    cin >> G >> P;

    for (int i = 1; i <= G; i++) {
        parent[i] = i;
    }

    int count = 0;
    int gate;
    int parentGate;
    for (int i = 0; i < P; i++) {
        cin >> gate;
        if ((parentGate = findRoot(gate)) == 0) break;
        merge(parentGate, parentGate - 1);
        count++;
    }

    cout << count;
}