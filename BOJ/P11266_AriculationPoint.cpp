#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj (10001);
int back [10001];
int discover_time = 0;
bool visited[10001] = {0,};
bool result [10001] = {0,};

int dfs(int root, bool isRoot){
    visited[root] = true;
    back[root] = discover_time++;
    int ret = back[root];
    int child = 0;

    for (int i = 0 ; i < adj[root].size() ; i++){
        if (!visited[adj[root][i]]){
            child++;
            int low = dfs(adj[root][i], false);
            if (!isRoot && low >= back[root]) {
                result[root] = true;
            }
            ret = min(ret, low);
        }else{
            ret = min(ret, back[adj[root][i]]);
        }
    }
    if(isRoot && child >= 2){
        result[root] = true;
    }
    return ret;
}

int main (){
    int v, e;

    scanf("%d %d", &v, &e);

    while(e--){
        int a, b;
        scanf("%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1 ; i<= v ; i++){
        if (!visited[i]){
            dfs(i, true);
        }
    }
    int cnt = 0;
    for (int i = 1 ; i <= v ; i++){
        if (result[i]) cnt++;
    }
    
    printf("%d\n", cnt);
    for (int i = 1 ; i <= v ; i++){
        if (result[i])printf("%d ", i);
    }
}
