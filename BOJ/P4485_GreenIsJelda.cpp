#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int map[126][126];
int dist[126][126];
bool visited[126][126];
int N;

struct Compare {
    bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};

bool isMovePossible(int row, int col) {
    return row <= N - 1 && row >= 0 && col <= N - 1 && col >= 0;
}

int dijkstra(int row, int col) {
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Compare> pq;
    int rowDir[] = { 1, -1, 0, 0 };
    int colDir[] = { 0, 0, 1, -1 };

    dist[row][col] = map[row][col];
    pq.push({ {row, col}, dist[row][col] });
    visited[row][col] = true;

    while (!pq.empty()) {
        int hereRow = pq.top().first.first;
        int hereCol = pq.top().first.second;
        int hereCost = pq.top().second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int thereRow = hereRow + rowDir[i];
            int thereCol = hereCol + colDir[i];

            if (isMovePossible(thereRow, thereCol) && !visited[thereRow][thereCol]) {
                int thereCost = hereCost + map[thereRow][thereCol];
                visited[thereRow][thereCol] = true;
                if (dist[thereRow][thereCol] > thereCost) {
                    dist[thereRow][thereCol] = thereCost;
                }

                pq.push({ {thereRow, thereCol}, dist[thereRow][thereCol] });
            }
        }
    }

    return dist[N - 1][N - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int testCount = 1;
    while (true) {

        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = INT_MAX;
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        cout << "Problem " << testCount++ << ": " << dijkstra(0, 0) << "\n";
    }
}
