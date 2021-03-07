#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

bool visited[1001][1001] = {false};
vector<vector<int>> board(1001, vector<int>(1001, 0));
vector<pair<int, int>> tomatoes;
int N, M;

bool isMovePossible(int nextRow, int nextCol)
{
    return nextRow >= 0 && nextRow < M && nextCol >= 0 && nextCol < N && board[nextRow][nextCol] != -1;
}

bool isAllRipe()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}

int bfs()
{
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    int move = 0;

    for (auto tomato : tomatoes)
    {
        visited[tomato.first][tomato.second] = true;
        q.push({tomato.first, tomato.second});
    }

    while (!q.empty())
    {
        unsigned long size = q.size();

        if (isAllRipe())
            return move;

        for (int i = 0; i < size; i++)
        {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextRow = rowDir[i] + currRow;
                int nextCol = colDir[i] + currCol;

                if (isMovePossible(nextRow, nextCol) && !visited[nextRow][nextCol])
                {
                    visited[nextRow][nextCol] = true;
                    board[nextRow][nextCol] = 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
        move++;
    }
    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1)
                tomatoes.push_back({i, j});
        }
    }
    printf("%d", bfs());
}
