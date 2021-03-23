#include <cstdio>
#include <algorithm>

using namespace std;

int map[1001][1001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int ans = 0;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1) ans = 1;
        }
    }

    for (int i = 1;i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (map[i][j] != 0 && map[i - 1][j] != 0 && map[i - 1][j - 1] != 0 && map[i][j - 1] != 0) {
                map[i][j] = min(map[i - 1][j], min(map[i - 1][j - 1], map[i][j - 1])) + 1;
                ans = max(ans, map[i][j]);
            }
        }
    }
    printf("%d", ans * ans);
}
