#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int border;
bool visited[301][301] = {0};

/* 방문여부 기록 초기화 */
void clearVisited(){
    for (int i = 0; i < border; i++){
        for (int j = 0; j < border; j++){
            visited[i][j] = false;
        }
    }
}

/* 말을 놓을 수 있는 자리인지 확인 */
bool isOverBorder(int x, int y){
    return x < 0 || y < 0 || x >= border || y >= border;
}

/* 정답 확인 */
bool isSolution(int x1, int y1, int x2, int y2){
    return x1 == x2 && y1 == y2;
}

int bfs(int startX, int startY, int destX, int destY){
    int xdir[] = {-2, -2, -1, -1, 1, 1, 2, 2}; // 나이트의 이동범위에 대한 x 좌표 조합 
    int ydir[] = {1, -1, 2, -2, 2, -2, 1, -1}; // 나이트의 이동범위에 대한 y 좌표 조합
    queue<pair<int, int>> q;
    int move = 0;

    visited[startY][startX] = true;
    q.push({startX, startY});

    while (!q.empty()){
        unsigned long size = q.size(); // 현재 큐의 크기를 통해서 depth 계산하기 
        
        for(int k = 0 ; k < size ; k++){
            int nodeX = q.front().first; // 큐에서 새로 꺼낸 위치의 x 좌표
            int nodeY = q.front().second; // 큐에서 새로 꺼낸 위치의 y 좌표
            q.pop();

            if (isSolution(nodeX, nodeY, destX, destY)) return move; // 정답을 찾으면 결과 리턴 
            
            for (int i = 0; i < 8; i++){ // 말을 놓을 수 있는 다음 좌표 계산. 총 8개의 위치가 가능
                int nextX = nodeX + xdir[i]; 
                int nextY = nodeY + ydir[i]; 
                
                if (!isOverBorder(nextX, nextY) && !visited[nextY][nextX]){ // 말을 놓을 수 있는 좌표이고 탐색한 적이 없는 자표라면 큐에 넣기
                    q.push({nextX, nextY});
                    visited[nextY][nextX] = true;
                }
            }
        }
        move++;
    }
    return 0;
}

int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        int currX, currY, destX, destY;
        clearVisited(); 

        scanf("%d", &border);
        scanf("%d %d", &currX, &currY);
        scanf("%d %d", &destX, &destY);
        
        int result = bfs(currX, currY, destX, destY); // bfs 수행
        printf("%d\n", result);
    }
}
