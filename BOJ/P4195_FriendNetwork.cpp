#include <cstdio>
#include <string>
#include <map>

using namespace std;

int parent[200001];
int cnt[200001];

int findRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findRoot(parent[x]);
}

int merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return cnt[a];

    if (a < b) {
        parent[b] = a;
        cnt[a] += cnt[b];
    }
    else {
        parent[a] = b;
        cnt[b] += cnt[a];
    }

    return a < b ? cnt[a] : cnt[b];
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        map<string, int> network;
        int friendIdx = 1;
        int F;
        scanf("%d", &F);

        for (int i = 1; i <= 200000; i++) {
            parent[i] = i;
            cnt[i] = 1;
        }

        for (int i = 0; i < F; i++) {
            char firstName[21];
            char secondName[21];
            int idxFirstName;
            int idxSecondName;

            scanf("%s %s", firstName, secondName);

            auto iterFirstName = network.find(firstName);
            auto iterSecondName = network.find(secondName);

            if (iterFirstName == network.end()) {
                network.insert({ firstName, friendIdx });
                idxFirstName = friendIdx++;
            }
            else idxFirstName = (*iterFirstName).second;

            if (iterSecondName == network.end()) {
                network.insert({ secondName, friendIdx });
                idxSecondName = friendIdx++;
            }
            else idxSecondName = (*iterSecondName).second;

            int ans = merge(idxFirstName, idxSecondName);

            printf("%d\n", ans);
        }
    }
}
