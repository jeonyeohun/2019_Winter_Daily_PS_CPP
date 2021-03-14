#include <iostream>
#include <vector>

using namespace std;

bool visited[101];
int depthCount = 0;

void dfs(vector<vector<int>> relationships, int start, int target, int depth)
{
    visited[start] = true;

    if (start == target)
    {
        depthCount = depth;
    }
    for (auto rel : relationships[start])
    {
        if (!visited[rel])
        {
            dfs(relationships, rel, target, depth + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, n;
    int start, target;
    cin >> N;
    cin >> start >> target;

    cin >> n;

    vector<vector<int>> relationships(N + 1);

    while (n--)
    {
        int x, y;
        cin >> x >> y;

        relationships[x].push_back(y);
        relationships[y].push_back(x);
    }

    dfs(relationships, start, target, 0);

    if (depthCount != 0)
        cout << depthCount;
    else
        cout << -1;
}
