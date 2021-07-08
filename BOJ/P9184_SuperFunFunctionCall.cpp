#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo[51][51][51];

int w(int a, int b, int c) {

    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20) {
        if (memo[20][20][20] == 0) return memo[20][20][20] = w(20, 20, 20);
        return memo[20][20][20];
    }

    if (a < b && b < c) {
        if (memo[a][b][c - 1] == 0) memo[a][b][c - 1] = w(a, b, c - 1);
        if (memo[a][b - 1][c - 1] == 0) memo[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        if (memo[a][b - 1][c] == 0) memo[a][b - 1][c] = w(a, b - 1, c);

        return memo[a][b][c] = memo[a][b][c - 1] + memo[a][b - 1][c - 1] - memo[a][b - 1][c];
    }


    if (memo[a - 1][b][c] == 0) memo[a - 1][b][c] = w(a - 1, b, c);
    if (memo[a - 1][b - 1][c] == 0) memo[a - 1][b - 1][c] = w(a - 1, b - 1, c);
    if (memo[a - 1][b][c - 1] == 0) memo[a - 1][b][c - 1] = w(a - 1, b, c - 1);
    if (memo[a - 1][b - 1][c - 1] == 0) memo[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);

    return memo[a][b][c] = memo[a - 1][b][c] + memo[a - 1][b - 1][c] + memo[a - 1][b][c - 1] - w(a - 1, b - 1, c - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ")" << " = " << w(a, b, c) << endl;
    }
}
