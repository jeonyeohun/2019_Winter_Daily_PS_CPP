#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> trees;
    vector<int> dists;
    int N, interval;
    int answer = 0;

    cin >> N;

    while (N--)
    {
        int n;
        cin >> n;
        trees.push_back(n);
    }

    sort(trees.begin(), trees.end());

    for (int i = 0; i < trees.size() - 1; i++)
    {
        dists.push_back(abs(trees[i] - trees[i + 1]));
    }

    interval = dists[0];
    for (int i = 1; i < dists.size() - 1; i++)
    {
        interval = gcd(interval, dists[i]);
    }

    for (auto dist : dists)
    {
        if (dist > interval)
        {
            answer += (dist / interval - 1);
        }
    }

    cout << answer;
}
