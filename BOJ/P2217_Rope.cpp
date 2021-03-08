#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int N;
    vector<int> ropes;

    scanf("%d", &N);

    while (N--)
    {
        int w;
        scanf("%d", &w);

        ropes.push_back(w);
    }

    sort(ropes.begin(), ropes.end(), greater<int>());

    int maxWeight = 0;
    int connectCount = 0;
    for (int i = 0; i < ropes.size(); i++)
    {
        connectCount++;
        maxWeight = max(maxWeight, ropes[i] * connectCount);
    }

    printf("%d", maxWeight);
}
