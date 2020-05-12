#include <cstdio>

using namespace std;

int parent[1000001];
int level[1000001] = {0};

int findRoot(int x){
    if (parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}

void merge(int a, int b){
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return;

    if (level[a] < level[b]) parent[b] = a;
    else parent[a] = b;
    if (level[a] == level[b]) level[b]++;
}

int main (){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0 ; i <= n ; i++){
        parent[i] = i;
    }
    while(m--){
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);

        switch (op){
            case 0: 
                merge(a,b);
                break;
            case 1:
                findRoot(a) == findRoot(b) ? printf("YES\n") : printf("NO\n");
                break;
        }
    }
}