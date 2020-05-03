#include <cstdio>

using namespace std;

bool visited[51][51];
bool map[51][51];


bool isWall (int a, int b){
    return (a < 0 || b < 0) ;
}

void dfs (int x, int y){
    int xdir[4] = {1, -1, 0, 0};
    int ydir[4] = {0, 0, 1, -1};
    
    visited[x][y] = true;
    
    for (int i = 0 ; i < 4 ; i++){
        if (isWall(x + xdir[i], y + ydir[i])) continue;
        if (map[x + xdir[i]][y + ydir[i]] == true && visited[x + xdir[i]][y + ydir[i]] == false){
            dfs(x + xdir[i], y + ydir[i]);
        }
    }
}

void resetArr(){
    for (int i = 0 ; i < 51 ; i++){
        for (int j = 0 ; j < 51 ; j++){
            map[i][j] = false;
            visited[i][j] = false;
        }
    }
}

int main (){
    int m, n, k;
    int T;

    scanf("%d", &T);

    while(T--){
        
        int count = 0;
        scanf("%d %d %d", &m, &n, &k);

        for (int i = 0 ; i < k ; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            map[x][y] = true;
        }
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (map[i][j] == true && visited[i][j] == false){
                    dfs(i, j);
                    count++;
                }
            }
        }
        resetArr();
        printf("%d\n", count);
    }
}
