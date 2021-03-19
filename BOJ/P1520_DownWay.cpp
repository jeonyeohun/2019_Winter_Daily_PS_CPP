#include <iostream>

using namespace std;

int M, N;

int map[501][501];
int dp[501][501];

bool isMovePossible(int row, int col)
{
    return row > 0 && row <= M && col > 0 && col <= N;
}

int dfs(int row, int col)
{
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};

    // 목적지까지 갈 수 있는 경로가 있다면 경우의 수를 하나 추가하기 위해 1을 반환한다.
    if (row == M && col == N)
    {
        return 1;
    }

    if (dp[row][col] == -1)
    {
        dp[row][col] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];

            if (isMovePossible(nextRow, nextCol) && map[row][col] > map[nextRow][nextCol])
            {
                dp[row][col] += dfs(nextRow, nextCol);
            }
        }
    }

    return dp[row][col];
}

int main()
{
    cin >> M >> N;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(1, 1);
}
