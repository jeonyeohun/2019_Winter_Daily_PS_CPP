#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
bool visited[1001][1001][2];
int N, M;

bool isMovePossible(int nextRow, int nextCol)
{
    return nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M;
}

int bfs(int row, int col, int isBreak)
{
    int rowDir[] = {0, 0, 1, -1};
    int colDir[] = {1, -1, 0, 0};

    queue<pair<pair<int, int>, bool>> q;
    int move = 1;

    visited[row][col][isBreak] = true;
    q.push({{row, col}, false});

    while (!q.empty())
    {
        unsigned long size = q.size();

        for (int k = 0; k < size; k++)
        {
            int posRow = q.front().first.first;
            int posCol = q.front().first.second;
            bool breakState = q.front().second;
            q.pop();

            if (posRow == N - 1 && posCol == M - 1)
                return move;

            for (int i = 0; i < 4; i++)
            {
                int nextRow = posRow + rowDir[i];
                int nextCol = posCol + colDir[i];

                if (isMovePossible(nextRow, nextCol))
                {
                    if (board[nextRow][nextCol] == 1 && breakState == false && !visited[nextRow][nextCol][0])
                    {
                        visited[nextRow][nextCol][0] = visited[nextRow][nextCol][1] = true;
                        q.push({{nextRow, nextCol}, true});
                    }

                    if (board[nextRow][nextCol] == 0 && breakState == false && !visited[nextRow][nextCol][0])
                    {
                        visited[nextRow][nextCol][0] = true;
                        q.push({{nextRow, nextCol}, breakState});
                    }

                    if (board[nextRow][nextCol] == 0 && breakState == true && !visited[nextRow][nextCol][1])
                    {
                        visited[nextRow][nextCol][1] = true;
                        q.push({{nextRow, nextCol}, breakState});
                    }
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
    vector<pair<int, int>> walls;

    for (int i = 0; i < N; i++)
    {
        vector<int> oneRow;
        for (int j = 0; j < M; j++)
        {
            int n;
            scanf("%1d", &n);
            oneRow.push_back(n);
            if (n == 1)
            {
                walls.push_back({i, j});
            }
        }
        board.push_back(oneRow);
    }

    printf("%d", bfs(0, 0, 0));
}
