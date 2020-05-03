#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int visited [100001] = {0,};

int bfs(int N, int K){
    queue<pair<int, int>> q;
    int distance = 0;
    q.push(make_pair(N, distance));

    while(!q.empty()){
        pair<int, int> v = q.front();
        if(v.first == K) break;
        q.pop();
        
        if(!visited[v.first]){
            if (v.first+1 <= 100000) q.push(make_pair(v.first+1, v.second+1));
            if (v.first-1 <= 100000) q.push(make_pair(v.first-1, v.second+1));
            if (v.first*1 <= 100000) q.push(make_pair(v.first*2, v.second+1));
            
            visited[v.first] = true;
        }
    }
    return q.front().second;
}

int main (){
    int N, K;

    scanf("%d %d", &N, &K);

    printf("%d", bfs(N, K));
}
