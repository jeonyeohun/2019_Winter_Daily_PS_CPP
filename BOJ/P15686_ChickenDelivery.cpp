#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<bool> visited(51, false);
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<int> selectedIdx;
int N, M;
int chickenDist = INT_MAX;

int calcDist(pair<int, int> house, pair<int, int> chicken)
{
    return abs(house.first - chicken.first) + abs(house.second - chicken.second);
}

void search(int cnt)
{
    if (selectedIdx.size() == M)
    {
        int sum = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            int minDist = INT_MAX;
            for (int j = 0; j < selectedIdx.size(); j++)
            {
                minDist = min(minDist, calcDist(houses[i], chickens[selectedIdx[j]]));
            }
            sum += minDist;
        }
        chickenDist = min(chickenDist, sum);
        return;
    }

    for (int i = cnt; i < chickens.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            selectedIdx.push_back(i);
            search(i + 1);
            selectedIdx.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cord;
            scanf("%d", &cord);
            if (cord == 2)
                chickens.push_back({i, j});
            if (cord == 1)
                houses.push_back({i, j});
        }
    }

    search(0);

    printf("%d", chickenDist);
}
