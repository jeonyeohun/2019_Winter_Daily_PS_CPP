#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

vector<ll> solution;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        ll s;
        cin >> s;
        solution.push_back(s);
    }

    sort(solution.begin(), solution.end());

    int head = 0, tail = N - 1;
    int first, second;
    ll sum = 0, minSum = LLONG_MAX;

    while (head < tail) {
        sum = solution[head] + solution[tail];
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            first = solution[head];
            second = solution[tail];
        }
        if (sum < 0) {
            head++;
        }
        else {
            tail--;
        }
    }

    cout << first << " " << second;
}

