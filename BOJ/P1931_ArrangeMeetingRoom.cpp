#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

bool pairSecondLess(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return (a.second < b.second);
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> greedy;

    for (int i = 0; i < N; i++)
    {
        int s, f;
        scanf("%d %d", &s, &f);
        greedy.push_back(make_pair(s, f));
    }

    sort(greedy.begin(), greedy.end(), pairSecondLess);

    vector<pair<int, int>> v;
    v.push_back(greedy[0]);
    for (int i = 1; i < greedy.size(); i++)
    {
        if (v.back().second <= greedy[i].first)
        {
            v.push_back(greedy[i]);
        }
    }

    printf("%ld", v.size());
}