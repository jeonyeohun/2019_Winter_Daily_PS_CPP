#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int map [101][101];
int visited [101][101];
int maxSafe = 0;
int N;

bool isWall (int row, int col){
    return (row < 0 || col < 0 || row >= N || col>=N);
}

void dfs (int row, int col, int height){
    visited[row][col] = true;
    int xdir [] = {0, 0, 1, -1};
    int ydir [] = {1, -1, 0, 0};

    for (int i = 0 ; i < 4 ; i++){
        int newrow = row+ydir[i];
        int newcol = col+xdir[i];
        if (isWall(newrow, newcol)) continue;
        
        if (!visited[newrow][newcol] && map[newrow][newcol]-height > 0){
            visited[newrow][newcol] = true;
            dfs(newrow, newcol, height);
        }
    }
}

void reInit (){
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            visited[i][j] = false;
        }
    }
    maxSafe = 0;
}

int main (){
    scanf("%d", &N);
    int maxh = 0;
    int result = 0;

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            scanf("%d", &map[i][j]);
            maxh = max(maxh, map[i][j]);
        }
    }
    
    for (int height = 0 ; height <= maxh ; height++){
        for (int i = 0 ; i < N ; i++){
            for (int j = 0 ; j < N ; j++){
                if (!visited[i][j] && map[i][j]-height > 0){
                    dfs(i, j, height);
                    maxSafe++;
                }
            }
        }
        result = max(maxSafe, result);
        reInit();
    }
    printf("%d", result);
}
