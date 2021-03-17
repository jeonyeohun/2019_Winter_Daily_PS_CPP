#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<vector<pair<int, ll>>> islands;
vector<bool> visited;

bool dfs(int start, int target, ll mid)
{
    visited[start] = true;

    if (start == target)
    {
        return true;
    }

    for (auto adj : islands[start])
    {
        int next = adj.first;
        ll nextCost = adj.second;

        if (!visited[next] && nextCost >= mid)
        {
            if (dfs(next, target, mid))
                return true;
            else
                continue;
        }
    }
    return false;
}

void clearVisit()
{
    for (int i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }
}

int main()
{
    int N, M;
    ll maxWeight = 0;
    int start, target;
    cin >> N >> M;
    islands.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        islands[a].push_back({b, c});
        islands[b].push_back({a, c});

        maxWeight = max(maxWeight, c);
    }

    cin >> start >> target;

    ll head = 0;
    ll tail = maxWeight;
    ll answer = 0;
    while (head <= tail)
    {
        ll mid = (head + tail) / 2;
        clearVisit();
        if (dfs(start, target, mid))
        {
            answer = mid;
            head = mid + 1;
        }
        else
        {
            tail = mid - 1;
        }
    }

    cout << answer;
}
