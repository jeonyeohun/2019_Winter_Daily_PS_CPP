#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> adj(1001);
int parent[1001];
int level[1001];

int findRoot (int x){
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}

int merge(int a, int b){
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return 0;
    if (level[a] > level[b]) parent[a] = b;
    else parent[b] = a;

    if (level[a] == level[b]) level[a]++;
    
    return 1;
}

int main (){
    int T;
    scanf("%d", &T);

    while(T--){
        
        int N, M;
        scanf("%d %d", &N, &M);
        
        for (int i = 0 ; i <= N ; i++){
            parent[i] = i;
        }

        int result = 0;
        for (int i = 0 ; i < M ; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            result+=merge(a, b);
        }
        
        printf("%d\n", result);
    }
}