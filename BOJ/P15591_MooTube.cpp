#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int> > > USADO;

int bfs(int cutoff, int start)
{
    bool visited[5001] = {false};
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int currPoint = q.front();
        q.pop();
        for (pair<int, int> adj : USADO[currPoint])
        {
            int nextPoint = adj.first;
            int relevantScore = adj.second;

            if (!visited[nextPoint] && relevantScore >= cutoff)
            {
                visited[nextPoint] = true;
                q.push(nextPoint);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    USADO.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;

        USADO[p].push_back({q, r});
        USADO[q].push_back({p, r});
    }

    while (Q--)
    {
        int k, v;
        cin >> k >> v;
        cout << bfs(k, v) << "\n";
    }
}
