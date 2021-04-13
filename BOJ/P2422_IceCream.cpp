#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int cnt = 0;
    int N, M;

    cin >> N >> M;
    vector<vector<bool>> disallowComb(N + 1, vector<bool>(N + 1, false));

    for (int i = 0;i < M; i++) {
        int a, b;
        cin >> a >> b;
        disallowComb[a][b] = true;
        disallowComb[b][a] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {
                if (!disallowComb[i][j] && !disallowComb[i][k] && !disallowComb[j][k]) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
}
