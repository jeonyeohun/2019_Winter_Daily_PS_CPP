#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > jewels;
multiset<int> bags;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        int weight;
        int value;

        scanf("%d %d", &weight, &value);

        jewels.push_back({weight, value});
    }

    sort(jewels.begin(), jewels.end(), comp);

    for (int i = 0; i < K; i++)
    {
        int bag;
        scanf("%d", &bag);
        bags.insert(bag);
    }

    long long sum = 0;
    for (auto jewel : jewels)
    {
        if (bags.empty())
            break;
        auto iter = bags.lower_bound(jewel.first); // 현재 보석의 무게 이상의 첫번째 가방을 찾는다.
        if (iter != bags.end())
        {
            sum += jewel.second; // 보석의 가치를 더하고
            bags.erase(iter);    // 해당 가방은 찾을 대상에서 제외시킨다.
        }
    }

    printf("%lld", sum);
}
