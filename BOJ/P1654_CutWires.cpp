#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> wires;

long long calcSum(long long c)
{
    long long sum = 0;
    for (long long wire : wires)
    {
        sum += (wire / c);
    }

    return sum;
}

long long binarySearch(long long begin, long long end, long long target)
{
    long long mid = 0;
    long long answer = 0;
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        long long result = calcSum(mid);

        if (result >= target)
        {
            answer = mid;
            begin = mid + 1;
        }
        else if (result < target)
            end = mid - 1;
    }

    return answer;
}

int main()
{
    long long K, N;
    long long longest = 0;
    scanf("%lld %lld", &K, &N);

    for (int i = 0; i < K; i++)
    {
        long long wire;
        scanf("%lld", &wire);

        wires.push_back(wire);
        longest = max(wire, longest);
    }

    printf("%lld", binarySearch(1, longest, N));
}
