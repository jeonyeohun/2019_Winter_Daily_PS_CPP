#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue<int> q;
vector<int> visited (1001, 0);

void bfs (vector<vector<int>> adj, int s){
    printf("%d ", s);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = 1;
        for (int i = 0 ; i < adj[node].size() ; i++){
            if (visited[adj[node][i]] == 0){
                visited[adj[node][i]] = 1;
                printf("%d ", adj[node][i]);
                q.push(adj[node][i]);
            }
        }
    }
}

void dfs (vector<vector<int>> adj, int s){
    visited[s] = 1;
    printf("%d ", s);
    for (int i = 0 ; i < adj[s].size() ; i++){
        if (visited[adj[s][i]] == 0){
            visited[adj[s][i]] = 1;
            dfs(adj, adj[s][i]);
        }
    }
}


int main (){
    int v, e, s;
    scanf("%d %d %d", &v, &e, &s);
    vector<vector<int>> adj (v+1);
    q.push(s);

    for (int i = 0 ; i < e ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0 ; i <= v ; i++){
        sort(adj[i].begin(), adj[i].end());  
    }
    dfs(adj, s);
    printf("\n");
    for (int i = 0 ; i <= v ; i++){
        visited[i] = 0;
    }
    bfs(adj, s);
}