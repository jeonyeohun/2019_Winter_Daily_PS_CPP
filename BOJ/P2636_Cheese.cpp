#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int board[101][101];
bool visited[101][101];
int N, M;

int countCheese()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 1)
                cnt++;
            if (board[i][j] == 2)
                board[i][j] = 0;
            visited[i][j] = false;
        }
    }
    return cnt;
}

bool isMovePossible(int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < M;
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
            if (board[nextRow][nextCol] == 1)
                board[nextRow][nextCol] = 2;
            else if (board[nextRow][nextCol] == 0)
            {
                dfs(nextRow, nextCol);
            }
        }
    }
}

int main()
{
    int prevCheese;
    int hrs = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0 && !visited[i][j])
            {
                hrs++;
                prevCheese = countCheese();
                dfs(i, j);

                if (countCheese() == 0)
                {
                    printf("%d\n%d", hrs, prevCheese);
                    exit(0);
                }
                i = j = 0;
            }
        }
    }
}
