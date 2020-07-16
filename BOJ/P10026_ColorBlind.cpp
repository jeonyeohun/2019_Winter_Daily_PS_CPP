#include <cstdio>

#define R 1
#define G 2
#define B 3

using namespace std;

bool visited[101][101];
int map[51][51];
int N;

bool isOverBoarder(int y, int x){
    return y < 0 || x < 0 || y > N || x > N;
}

void dfs_normal (int y, int x){
    visited[y][x] = true;
    int xdir [] = {0, 0, 1, -1};
    int ydir [] = {1, -1, 0, 0}; 
    int key = map[y][x];

    for (int i = 0 ; i < 4 ; i++){
        int newX = x + xdir[i];
        int newY = y + ydir[i];

        if(!visited[newY][newX] && !isOverBoarder(newY, newX)){
            if(map[newY][newX] == key) dfs_normal(newY, newX);
        }
        
    }
}

int main (){
    scanf("%d", &N);

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            char c;
            scanf("%c", &c);

            if (c == 'R') map[i][j] = R;
            else if (c == 'G') map[i][j] = G;
            else if (c == 'B') map[i][j] = B;
        }
        getchar();
    }

    int normal = 0;
    for (int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if (!visited[i][j]) {
                dfs_normal(i, j);
                normal++;
                printf("%d %d\n", i, j);
            }
        }
    }

    printf("%d", normal);
}