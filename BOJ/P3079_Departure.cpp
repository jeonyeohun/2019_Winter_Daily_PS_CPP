#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> times;

ll calcPeople(ll mid)
{
    ll sum = 0;
    for (auto time : times)
    {
        sum += (mid / time);
    }

    return sum;
}

ll binarySearch(ll head, ll tail, ll target)
{
    ll mid = 0;
    ll result = 0;
    while (head <= tail)
    {
        mid = (head + tail) / 2;
        ll maxPeople = calcPeople(mid);

        if (maxPeople >= target)
        {
            tail = mid - 1;
            result = mid;
        }
        else
        {
            head = mid + 1;
        }
    }
    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;
    ll maxTime = 0;

    for (int i = 0; i < N; i++)
    {
        ll time;
        cin >> time;
        times.push_back(time);
        maxTime = max(maxTime, time);
    }

    cout << binarySearch(1, maxTime * M, M);
}
