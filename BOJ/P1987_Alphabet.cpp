#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 21;

int R, C;
bool alphaUsed[26];
char board[MAX][MAX];

int maxMove = 0;

bool isMovePossible(int r, int c)
{
    return (r >= 0 && r < R) && (c >= 0 && c < C);
}

void dfs(int row, int col, int move)
{
    alphaUsed[board[row][col] - 65] = true;

    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + rowDir[i];
        int nextCol = col + colDir[i];
        if (isMovePossible(nextRow, nextCol) && !alphaUsed[board[nextRow][nextCol] - 65])
        {
            dfs(nextRow, nextCol, move + 1);
        }
    }
    alphaUsed[board[row][col] - 65] = false;
    maxMove = max(maxMove, move);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 1);

    cout << maxMove;
}
