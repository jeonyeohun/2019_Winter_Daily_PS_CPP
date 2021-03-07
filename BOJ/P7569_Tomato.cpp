#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

bool visited[101][101][101] = {false};
int board[101][101][101];
vector<pair<int, pair<int, int>>> tomatoes;
int N, M, H;

bool isMovePossible(int nextRow, int nextCol, int currLevel)
{
    return nextRow >= 0 && nextRow < M && nextCol >= 0 && nextCol < N && board[currLevel][nextRow][nextCol] != -1;
}

bool isAllRipe()
{
    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[h][i][j] == 0)
                    return false;
            }
        }
    }
    return true;
}

int bfs()
{
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};
    int heightDir[] = {1, -1};

    queue<pair<int, pair<int, int>>> q;
    int move = 0;

    for (auto tomato : tomatoes)
    {
        int level = tomato.first;
        int row = tomato.second.first;
        int col = tomato.second.second;
        visited[level][row][col] = true;
        q.push({level, {row, col}});
    }

    while (!q.empty())
    {
        unsigned long size = q.size();

        if (isAllRipe())
            return move;

        for (int i = 0; i < size; i++)
        {
            int currLevel = q.front().first;
            int currRow = q.front().second.first;
            int currCol = q.front().second.second;
            q.pop();

            for (int i = 0; i < 2; i++)
            {
                int nextLevel = currLevel + heightDir[i];
                if (nextLevel >= 0 && nextLevel < H && !visited[nextLevel][currRow][currCol] && board[nextLevel][currRow][currCol] == 0)
                {
                    visited[nextLevel][currRow][currCol] = true;
                    board[nextLevel][currRow][currCol] = 1;
                    q.push({nextLevel, {currRow, currCol}});
                }
            }

            for (int i = 0; i < 4; i++)
            {
                int nextRow = rowDir[i] + currRow;
                int nextCol = colDir[i] + currCol;

                if (isMovePossible(nextRow, nextCol, currLevel) && !visited[currLevel][nextRow][nextCol])
                {
                    visited[currLevel][nextRow][nextCol] = true;
                    board[currLevel][nextRow][nextCol] = 1;
                    q.push({currLevel, {nextRow, nextCol}});
                }
            }
        }
        move++;
    }
    return -1;
}

int main()
{
    scanf("%d %d %d", &N, &M, &H);

    for (int h = 0; h < H; h++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &board[h][i][j]);
                if (board[h][i][j] == 1)
                    tomatoes.push_back({h, {i, j}});
            }
        }
    }
    printf("%d", bfs());
}
