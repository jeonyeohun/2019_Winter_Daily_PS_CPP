#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> adj (32001);
stack<int> lineup;
bool visited[32001];

void dfs (int s){
    visited[s] = true;
    
    for (int i = 0 ; i < adj[s].size() ; i++){
        if (!visited[adj[s][i]]){
            dfs(adj[s][i]);
        }
    }
    lineup.push(s);
}

int main (){
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i = 0 ; i < M ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }

    for (int i = 1 ; i <= N ; i++){
        if (!visited[i]){
            dfs(i);
        }
    }

    while(!lineup.empty()){
        printf("%d ", lineup.top());
        lineup.pop();
    }
}
