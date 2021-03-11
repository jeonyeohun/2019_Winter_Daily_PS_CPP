#include <cstdio>
#include <set>

using namespace std;

set<int> houses;
int N, C;

int installRouter(int interval)
{
    int count = 1;
    int point = *(houses.begin()) + interval;
    while (true)
    {
        auto iter = houses.lower_bound(point);
        if (iter != houses.end())
        {
            count++;
        }
        else if (iter == houses.end())
            break;

        point = *iter + interval;
    }

    return count;
}

int binarySearch()
{
    int head = 1;
    int tail = *(houses.rbegin());
    int answer = 0;

    while (head <= tail)
    {
        int mid = (tail + head) / 2;
        int result = installRouter(mid);

        if (result >= C)
        {
            head = mid + 1;
            answer = mid;
        }
        else
            tail = mid - 1;
    }

    return answer;
}

int main()
{

    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++)
    {
        int house;
        scanf("%d", &house);

        houses.insert(house);
    }

    printf("%d", binarySearch());
}
