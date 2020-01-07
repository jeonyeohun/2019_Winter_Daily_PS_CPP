#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, bool>> visited;
vector<int> v (8, 0);

void DFS(int cnt){
    if (cnt == M) {
        for (int i = 0 ; i < M ; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0 ; i < visited.size() ; i++){
        if(!visited[i].second){
            visited[i].second = true;
            v[cnt] = visited[i].first;
            DFS(cnt+1);
            visited[i].second = false;
        }
    }
}

int main (){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        int n;
        cin >> n;
        visited.emplace_back(make_pair(n, false));
    }
    sort(visited.begin(), visited.end());
    DFS(0);
}