#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    long long int min, max;
    cin >> min >> max;

    vector<bool> primes(max - min + 1, false);

    for (long long int i = 2; i <= max; i++)
    {
        long long int sqr = i * i;

        if (sqr > max)
            break;
        long long int start = (min / sqr) * sqr;
        if (start < min)
            start += sqr;

        for (long long int j = start; j <= max; j += (i * i))
        {
            primes[j - min] = true;
        }
    }

    int answer = 0;
    for (int i = 0; i <= max - min; i++)
    {
        if (!primes[i])
            answer++;
    }

    cout << answer;
}
