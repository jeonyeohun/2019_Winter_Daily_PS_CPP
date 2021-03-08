#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 101;

bool board[MAX][MAX];
bool visited[MAX][MAX];
int cnt = 1;

int M, N, K;

bool isMovePossible(int row, int col)
{
    return M > col && 0 <= col && N > row && 0 <= row && board[row][col] == false;
}

void dfs(int row, int col)
{
    visited[row][col] = true;
    int rowDir[] = {0, 0, 1, -1};
    int colDir[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + rowDir[i];
        int nextCol = col + colDir[i];
        if (isMovePossible(nextRow, nextCol) && !visited[nextRow][nextCol])
        {
            cnt++;
            visited[nextRow][nextCol] = true;
            dfs(nextRow, nextCol);
        }
    }
}

void fillBoard(int leftBottomRow, int leftBottomCol, int rightTopRow, int rightTopCol)
{
    for (int i = leftBottomRow; i < rightTopRow; i++)
    {
        for (int j = leftBottomCol; j < rightTopCol; j++)
        {
            board[i][j] = true;
        }
    }
}

int main()
{
    scanf("%d %d %d", &M, &N, &K);
    vector<int> areas;

    for (int i = 0; i < K; i++)
    {
        int leftBottomRow, leftBottomCol, rightTopRow, rightTopCol;
        scanf("%d %d %d %d", &leftBottomRow, &leftBottomCol, &rightTopRow, &rightTopCol);
        fillBoard(leftBottomRow, leftBottomCol, rightTopRow, rightTopCol);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!board[i][j] && !visited[i][j])
            {
                dfs(i, j);
                areas.push_back(cnt);
                cnt = 1;
            }
        }
    }

    sort(areas.begin(), areas.end());

    printf("%d\n", areas.size());
    for (auto area : areas)
    {
        printf("%d ", area);
    }
}
