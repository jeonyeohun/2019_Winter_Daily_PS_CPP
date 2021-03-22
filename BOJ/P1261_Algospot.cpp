#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool map[102][102];
int dist[102][102];
bool visited[102][102];
int M, N;

struct Compare {
    bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};

bool isMovePossible(int row, int col) {
    return row <= N && row > 0 && col <= M && col > 0;
}

void dijkstra(int row, int col) {
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Compare> pq;

    int rowDir[] = { 1, -1, 0, 0 };
    int colDir[] = { 0, 0, 1, -1 };

    pq.push({ { row, col }, 0 });
    dist[row][col] = 0;

    while (!pq.empty()) {
        int hereRow = pq.top().first.first;
        int hereCol = pq.top().first.second;
        int hereBreakCount = pq.top().second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int thereRow = hereRow + rowDir[i];
            int thereCol = hereCol + colDir[i];
            int thereBreakCount = dist[thereRow][thereCol];

            if (isMovePossible(thereRow, thereCol) && !visited[thereRow][thereCol]) {
                if (map[thereRow][thereCol] == 0) {
                    thereBreakCount = min(thereBreakCount, hereBreakCount);
                }
                else if (map[thereRow][thereCol] == 1) {
                    thereBreakCount = min(thereBreakCount, hereBreakCount + 1);
                }

                visited[thereRow][thereCol] = true;
                dist[thereRow][thereCol] = thereBreakCount;
                pq.push({ {thereRow, thereCol}, thereBreakCount });
            }
        }
    }
}


int main() {
    scanf("%d %d", &M, &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    dijkstra(1, 1);

    printf("%d", dist[N][M]);
}
