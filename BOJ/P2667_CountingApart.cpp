#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int visited [26][26];
int map [26][26];

int dirX [4] = {0, 0, 1, -1};
int dirY [4] = {1, -1, 0, 0};

int cnt = 1;
int total = 0;

void dfs (int x, int y){
    visited[x][y] = 1;
    for (int i = 0 ; i < 4 ; i++){
        if (!visited[x+dirX[i]][y+dirY[i]] && map[x+dirX[i]][y+dirY[i]] == 1){
            cnt++;
            dfs(x+dirX[i], y+dirY[i]);    
        } 
    }
}

int main (){
    int N;
    scanf("%d", &N);
    vector<int> result;

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            scanf("%1d", &map[i][j]);
            visited[i][j] = 0;
        }
    }

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            if (visited[i][j] == 0 && map[i][j] == 1){
                dfs(i, j);
                total++;
                result.push_back(cnt);
            }
            cnt = 1;
        }
    } 
    sort(result.begin(), result.end());

    printf("%d\n",total);
    for (auto i : result){
        printf("%d\n", i);
    }
}