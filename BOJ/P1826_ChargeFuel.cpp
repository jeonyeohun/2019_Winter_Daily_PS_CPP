#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    vector<pair<int, int>> stations;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        stations.push_back({a, b});
    }

    sort(stations.begin(), stations.end());

    int L, P;
    cin >> L >> P;

    int currFuel = P;
    int stationCount = 0;
    while (currFuel < L)
    {
        for (auto iter = stations.begin(); iter != stations.end() && !stations.empty(); iter++)
        {
            if ((*iter).first <= currFuel)
            {
                pq.push(*iter);
                iter = stations.erase(iter);
                iter--;
            }
        }

        if (pq.empty())
        {
            cout << -1;
            return 0;
        }

        currFuel += pq.top().second;
        pq.pop();
        stationCount++;
    }

    cout << stationCount;
}
