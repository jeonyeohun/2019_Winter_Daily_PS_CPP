#include <iostream>
#include <vector>
#include <set>

using namespace std;

int parent[10001];
int level[10001];

vector<int> friends(10001, 0);

int findRoot(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = findRoot(parent[x]);
}

void merge(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);

    if (a == b)
        return;

    if (friends[a] > friends[b])
        parent[a] = b;
    else
        parent[b] = a;

    if (level[a] == level[b])
        level[b]++;
}

int main()
{
    int N, M, k;
    cin >> N >> M >> k;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> friends[i];
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    for (int i = 1; i <= N; i++)
    {
        findRoot(i);
    }

    set<int> roots;
    for (int i = 1; i <= N; i++)
    {
        roots.insert(parent[i]);
    }

    int friendCost = 0;
    for (auto root : roots)
    {
        friendCost += friends[root];
    }

    if (friendCost <= k)
        cout << friendCost;
    else
        cout << "Oh no";
}
