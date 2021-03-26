#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int dist[401][401] = { 0, };
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = -1;
    }

    for (int m = 1; m <= n; m++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][m] == -1 && dist[m][j] == -1) dist[i][j] = -1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == -1) {
                dist[j][i] = 1;
            }
        }
    }

    int s;
    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }

}