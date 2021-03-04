#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000001;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> primes(MAX, true);

    primes[1] = false;
    for (int i = 3; i <= sqrt(MAX); i += 2)
    {
        for (int j = i + i; j <= MAX; j += i)
        {
            primes[j] = false;
        }
    }

    while (true)
    {
        bool foundSolution = false;
        int n;
        cin >> n;

        if (n == 0)
            break;

        for (int i = 3; i < n; i += 2)
        {
            if (primes[i] && primes[n - i])
            {
                foundSolution = true;
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
        }
        if (!foundSolution)
        {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}
