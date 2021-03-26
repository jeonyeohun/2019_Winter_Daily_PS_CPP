#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    bool dist[N + 1][N + 1];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> dist[i][j];
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j]) continue;
                dist[i][j] = dist[i][k] && dist[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
