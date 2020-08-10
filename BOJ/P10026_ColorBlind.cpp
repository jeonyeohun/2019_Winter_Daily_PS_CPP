#include <cstdio>

#define R 1
#define G 2
#define B 3

using namespace std;

bool visited_normal[101][101];
bool visited_blind[101][101];
int map[51][51];
int N;

bool isOverBoarder(int y, int x){
    return y < 0 || x < 0 || y > N || x > N;
}

void dfs_normal (int y, int x){
    visited_normal[y][x] = true;
    int xdir [] = {0, 0, 1, -1};
    int ydir [] = {1, -1, 0, 0};
    int key = map[y][x];

    for (int i = 0 ; i < 4 ; i++){
        int newX = x + xdir[i];
        int newY = y + ydir[i];

        if(!visited_normal[newY][newX] && !isOverBoarder(newY, newX)){
            if(map[newY][newX] == key) dfs_normal(newY, newX);
        }
        
    }
}

void dfs_blind (int y, int x){
    visited_blind[y][x] = true;
    
    int xdir [] = {0, 0, 1, -1};
    int ydir [] = {1, -1, 0, 0};
    int key = map[y][x];
    
    for (int i = 0 ; i < 4 ; i++){
        int newX = x + xdir[i];
        int newY = y + ydir[i];

        if(!visited_blind[newY][newX] && !isOverBoarder(newY, newX)){
            if (key == R && map[newY][newX] == G) dfs_blind(newY, newX);
            else if (key == G && map[newY][newX] == R) dfs_blind(newY, newX);
            else if (map[newY][newX] == key) dfs_blind(newY, newX);
        }
        
    }
}

int main (){
    scanf("%d", &N);
    getchar();
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
            if (!visited_normal[i][j]) {
                dfs_normal(i, j);
                normal++;
            }
        }
    }
    
    
    int blind = 0;
    for (int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if (!visited_blind[i][j]) {
                dfs_blind(i, j);
                blind++;
            }
        }
    }

    printf("%d %d", normal, blind);
}
