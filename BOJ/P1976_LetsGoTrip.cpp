#include <iostream>
#include <vector>

using namespace std;

int parent[201];
int level[201];

int findRoot(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findRoot(parent[x]);
}

bool merge(int a, int b)
{

    a = findRoot(a);
    b = findRoot(b);

    if (a == b)
        return false;

    if (level[a] < level[b])
        parent[b] = a;
    else
        parent[a] = b;

    if (level[a] == level[b])
        level[b]++;

    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            bool isConnected;
            cin >> isConnected;

            if (isConnected)
            {
                merge(i, j);
            }
        }
    }

    vector<int> route;
    for (int i = 0; i < M; i++)
    {
        int dest;
        cin >> dest;
        route.push_back(dest);
    }

    int root = findRoot(route[0]);
    int i;
    for (i = 1; i < M; i++)
    {
        if (root != findRoot(route[i]))
        {
            break;
        }
    }

    if (i == M)
        cout << "YES";
    else
        cout << "NO";
}