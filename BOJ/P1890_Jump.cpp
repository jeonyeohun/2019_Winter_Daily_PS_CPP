#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    int map[101][101];
    ull dp[101][101];

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == 1 && j == 1)
                continue;
            {
                ull rowCount = 0;
                ull colCount = 0;
                for (int row = 1; row < i; row++)
                {
                    if (map[row][j] == i - row)
                    {
                        rowCount += dp[row][j];
                    }
                }
                for (int col = 1; col < j; col++)
                {
                    if (map[i][col] == j - col)
                    {
                        colCount += dp[i][col];
                    }
                }

                dp[i][j] = rowCount + colCount;
            }
        }
    }

    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << dp[N][N];
}
