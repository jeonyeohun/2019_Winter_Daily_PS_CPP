#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 2000000;
vector<bool> primes(MAX + 1, true);
vector<int> primeNums;

bool isPrime(long long int target)
{
    if (target <= MAX)
        return primes[target];
    for (int i = 0; i < primeNums.size(); i++)
    {
        if (target % primeNums[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    primes[0] = primes[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++)
    {
        for (int j = i + i; j <= MAX; j += i)
        {
            primes[j] = false;
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (primes[i])
            primeNums.push_back(i);
    }

    while (T--)
    {
        long long int A, B;
        cin >> A >> B;
        long long int sum = A + B;

        if (sum < 4)
            cout << "NO\n";
        else if (sum % 2 == 0)
            cout << "YES\n";
        else if (isPrime(sum - 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
