#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];
int level[10001];
vector<pair<pair<int, int>, int>> edges;

bool comp (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second < b.second;
}

int findRoot (int x){
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}

bool merge(int a, int b){
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return false;
    if (level[a] > level[b]) parent[a] = b;
    else parent[b] = a;

    if (level[a] == level[b]) level[a]++;
    return true;
}

int main (){
    int v, e;
    int result = 0;
    scanf("%d %d", &v, &e);

    for (int i = 0 ; i <= v ; i++){
        parent[i] = i;
    }

    for (int i = 0 ; i < e ; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back(make_pair(make_pair(a, b), c));
    }

    sort(edges.begin(), edges.end(), comp);

    for (auto i : edges){
        if(merge(i.first.first, i.first.second)) {
            result += i.second;
        }
    }

    printf("%d", result);
}