#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int P[502][502];
    int minCost[502][502];

    for (int i = 1; i <= N; i++)
    {
        cin >> P[i][0];
        cin >> P[i][1];
    }

    for (int l = 2; l <= N; l++)
    {
        for (int i = 1; i <= N - l + 1; i++)
        {
            int j = i + l - 1;
            minCost[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = minCost[i][k] + minCost[k + 1][j] + P[i][0] * P[k][1] * P[j][1];
                minCost[i][j] = min(q, minCost[i][j]);
            }
        }
    }
    cout << minCost[1][N];
}