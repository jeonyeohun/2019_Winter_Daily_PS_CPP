#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool rel[101][101] = { 0, };
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        rel[a][b] = true;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    rel[i][j] = true;
                    continue;
                }
                else if (rel[i][j] == false) {
                    rel[i][j] = rel[i][k] && rel[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (rel[i][j]) rel[j][i] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            if (rel[i][j] == false) sum++;
        }
        cout << sum << "\n";
    }
}