#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(101);
bool visited [101];
int result = 0;

void bfs (int s){
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for (int i = 0 ; i < adj[node].size() ; i++){
            if (!visited[adj[node][i]]){
                result++;
                q.push(adj[node][i]);
                visited[adj[node][i]] = true;
            }
        }
        
    }
}

int main (){
    int v, e;
    
    scanf("%d %d", &v, &e);


    for (int i = 0 ; i < e ; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);   
    }
    
    visited[1] = true;
    bfs(1);

    printf("%d", result);
}