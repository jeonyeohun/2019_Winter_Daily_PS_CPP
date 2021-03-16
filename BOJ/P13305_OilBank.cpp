#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long long dist[N - 1];
    long long cost[N];

    for (int i = 0; i < N - 1; i++)
    {
        cin >> dist[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }

    long long minCost = INT_MAX;
    long long totalCost = 0;
    for (int i = 0; i < N - 1; i++)
    {
        minCost = min(minCost, cost[i]);
        totalCost += minCost * dist[i];
    }

    cout << totalCost;
}