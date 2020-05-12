#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[10001];
vector<vector<int>> result;
vector<vector<int>> adj;
vector<vector<int>> adjTrans;
stack<int>stk;

void dfs(int root){
    visited[root] = true;
    for (int  i = 0 ; i < adj[root].size() ; i++){
        if (!visited[adj[root][i]]){
            dfs(adj[root][i]);
        }
    }
    stk.push(root);
}

void scc(int root){
    visited[root] = true;
    for (int  i = 0 ; i < adjTrans[root].size() ; i++){
        if (!visited[adjTrans[root][i]]){
            scc(adjTrans[root][i]);
            result.back().push_back(adjTrans[root][i]);
        }
    }
}

int main (){
    int V, E;
    
    scanf("%d %d", &V, &E);
    
    adj.resize(V+1);
    adjTrans.resize(V+1);

    for (int i = 0 ; i < E  ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adjTrans[b].push_back(a);
    }

    for (int i = 1 ; i <= V ; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    for (int i = 0 ; i <=V ; i++) visited[i] = false;
    
    while(!stk.empty()){
        if (!visited[stk.top()]){
            vector<int> temp(1);
            temp[0] = stk.top();
            result.push_back(temp);
            scc(stk.top());
        }
        stk.pop();
    }
    
    printf("%lu\n", result.size());
  
    for (int i = 0 ; i < result.size() ; i++){
        sort(result[i].begin(), result[i].end());
    }
    
    sort(result.begin(), result.end());
    for (auto v : result){
        for (auto i : v){
            printf("%d ", i);
        }
        printf("-1\n");
    }
}

