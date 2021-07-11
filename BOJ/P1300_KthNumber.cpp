#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll countValid(ll N, ll target) {
    ll count = 0;
    for (ll i = 1; i <= N; i++) {
        count += min(N, target / i);
    }
    return count;
}

ll binarySearch(ll start, ll end, ll target, ll N) {
    ll ans = -1;
    while (start <= end) {
        ll mid = (start + end) / 2;
        ll count = countValid(N, mid);
        if (count < target) {
            start = mid + 1;
        }
        else {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll N, k;
    cin >> N >> k;

    cout << binarySearch(1, N * N, k, N);
}
