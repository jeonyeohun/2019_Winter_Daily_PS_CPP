#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> budgets;

ll calcBudget(ll maxBudget)
{
    ll sum = 0;
    for (auto budget : budgets)
    {
        if (budget <= maxBudget)
            sum += budget;
        else
            sum += maxBudget;
    }

    return sum;
}

ll binarySearch(ll head, ll tail, ll target)
{
    ll closest = 0;

    while (head <= tail)
    {
        ll mid = (head + tail) / 2;
        ll calcResult = calcBudget(mid);

        if (calcResult > target)
            tail = mid - 1;
        else if (calcResult <= target)
        {
            closest = mid;
            head = mid + 1;
        }
    }

    return closest;
}

int main()
{
    int N;
    ll M, longest = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        ll budget;
        scanf("%lld", &budget);

        budgets.push_back(budget);

        longest = max(longest, budget);
    }

    scanf("%lld", &M);

    printf("%lld", binarySearch(0, longest, M));
}
