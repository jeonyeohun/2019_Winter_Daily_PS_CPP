#include <cstdio>
#include <utility>

using namespace std;

int N, M;
int map[51][51];
int steps = 1;

bool isInMap(int row, int col)
{
    return row >= 1 && row <= N && col >= 1 && col <= M;
}

void dfs(int row, int col, int dir)
{

    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, 1, 0, -1};
    int rowRearDir[] = {1, 0, -1, 0};
    int colRearDir[] = {0, -1, 0, 1};

    if (map[row][col] == 0)
    {
        steps += 1;
        map[row][col] = steps;
    }

    for (int i = dir - 1; i > dir - 5; i--)
    {
        int nextDir = (i + 4) % 4;
        int nextRow = row + rowDir[nextDir];
        int nextCol = col + colDir[nextDir];

        if (isInMap(nextRow, nextCol) && map[nextRow][nextCol] == 0)
        {
            dfs(nextRow, nextCol, nextDir);
            return;
        }
    }

    int nextRearRow = row + rowRearDir[dir];
    int nextRearCol = col + colRearDir[dir];
    if (!(map[nextRearRow][nextRearCol] == 1))
    {
        dfs(nextRearRow, nextRearCol, dir);
    }
}

int main()
{

    scanf("%d %d", &N, &M);

    int r, c, dir;
    scanf("%d %d %d", &r, &c, &dir);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    dfs(r, c, dir);

    printf("%d", steps - 1);
}
