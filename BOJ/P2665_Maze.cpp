#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int n;
vector<vector<bool>> map;
vector<vector<int>> dist;

bool isInBound(int row, int col) {
    return row >= 1 && row <= n && col >= 1 && col <= n;
}

void bfs() {
    int minChange = n * n;
    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({ 0, {1, 1} });

    int rowDir[] = { 1, 0, -1, 0 };
    int colDir[] = { 0, 1, 0, -1 };

    while (!pq.empty()) {
        pair<int, pair<int, int>> now = pq.top();
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nextRow = now.second.first + rowDir[i];
            int nextCol = now.second.second + colDir[i];

            if (isInBound(nextRow, nextCol)
                && map[nextRow][nextCol] == 1
                && now.first < dist[nextRow][nextCol]) {
                dist[nextRow][nextCol] = now.first;
                pq.push({ now.first,{ nextRow, nextCol} });
            }
            else if (isInBound(nextRow, nextCol)
                && map[nextRow][nextCol] == 0
                && now.first + 1 < dist[nextRow][nextCol]) {
                dist[nextRow][nextCol] = now.first + 1;
                pq.push({ now.first + 1,{ nextRow, nextCol} });
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    map.resize(n + 1, vector<bool>(n + 1));
    dist.resize(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int point;
            scanf("%1d", &point);
            map[i][j] = (bool)point;
        }
    }

    bfs();
    printf("%d", dist[n][n]);
}