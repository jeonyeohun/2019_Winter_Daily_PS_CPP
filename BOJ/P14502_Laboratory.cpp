#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_LEN 8

bool visited [MAX_LEN][MAX_LEN] = {0};

int row, col;
int solution = 0;

/* 보드판을 넘어서는 좌표인지 확인하기 */
bool isOverBorder(int y, int x){
    return x < 0 || y < 0 || y >= row ||  x >= col ;
}

/* 빈칸 좌표인지 확인하기 */
bool isBlank(int target){
    return target == 0;
}

/* 방문여부 초기화 */
void clearVisited(){
    for(int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            visited[i][j] = false;
        }
    }
}

/* DFS로 가능한 모든 좌표를 바이러스로 만들기 */
void spreadVirus(int board [MAX_LEN][MAX_LEN], int y, int x){
    int xdir [] = {1, 0, -1, 0};
    int ydir [] = {0, 1, 0, -1};
    
    visited[y][x] = true;

    for (int i = 0 ; i < 4 ; i++){
        int newX = xdir[i] + x;
        int newY = ydir[i] + y;
        if (!isOverBorder(newY, newX) && !visited[newY][newX] && isBlank(board[newY][newX])){
            board[newY][newX] = 2;
            spreadVirus(board, newY, newX);
        }
    }
}

/* 현재 보드의 0의 개수 세기 */
int getSafeSiteSize(int board [MAX_LEN][MAX_LEN]){
    int ret = 0;
    for(int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            if (board[i][j] == 0) ret++;
        }
    }
    return ret;
}

/* 배열 복사 */
int copyArray(int ** src, int ** dest){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            dest[i][j] = src[i][j];
        }
    }
}

/* 백트래킹을 사용해 모든 가능한 벽 시도 */
void setWall (int board [MAX_LEN][MAX_LEN], int size){
    /* 벽을 3개 세웠을 때 */
    if(size == 3){
        clearVisited();
        int tempboard[MAX_LEN][MAX_LEN] = {0};
        copyArray(board, tempboard); // 벽을 세운 임시보드 생성
        
        for (int i = 0 ; i < row ; i++){
            for (int j = 0 ; j < col ; j++){
                if (tempboard[i][j] == 2 && !visited[i][j]){
                    spreadVirus(tempboard, i, j); // 모든 가능한 바이러스 퍼뜨리기(DFS)
                }
            }
        }
        
        solution = max(getSafeSiteSize(tempboard), solution); // 0의 개수를 세서 더 큰 값을 최종 값으로 저장
        return;
    }
    for (int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            if (!isOverBorder(i, j) && board[i][j] == 0){
                board[i][j] = 1;
                setWall(board, size+1);
                board[i][j] = 0;
            }
        }
    }
}

int main (){
    int map [MAX_LEN][MAX_LEN] = {0};
    
    scanf("%d %d", &row, &col);

    /* 좌표 리딩 */
    for (int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            scanf("%d", &map[i][j]);
        }
    }

    /* 벽세우기 */
    setWall(map, 0);
    printf("%d", solution);

}