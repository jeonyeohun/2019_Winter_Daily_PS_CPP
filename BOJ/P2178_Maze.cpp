#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

bool visited [101][101];
bool map[101][101];
int N, M;
int cnt = 0;

vector<vector<int>> adj (101);

void bfs(int y, int x){
    queue<pair<int, int>> q;
    int xdir [] = {1, -1, 0, 0};
    int ydir [] = {0, 0, 1, -1};

    q.push(make_pair(y, x));
    visited[y][x] = true;

    while(!q.empty()){
        int size = q.size();
        for (int k = 0 ; k < size ; k++){
            pair<int, int> node = q.front();
            q.pop();
            if ((node.first == N) && node.second == M) return;
            for (int i = 0 ; i < 4 ; i++){
                int nextY = node.first + ydir[i];
                int nextX = node.second + xdir[i];

                if (map[nextY][nextX] == true && visited[nextY][nextX] == false){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
        cnt++;
    }
}

int main (){
    scanf ("%d %d", &N, &M);

    for (int i = 1 ; i <= N ; i++){
        for (int j = 1 ; j <= M ; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(1, 1);
    printf("%d", cnt+1);
}