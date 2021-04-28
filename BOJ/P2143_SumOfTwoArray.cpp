#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, n, m;
    cin >> T >> n;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<long long> sumA(A.begin(), A.end());
    vector<long long> sumB(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
        long long sum = A[i];
        for (int j = i + 1; j < A.size(); j++) {
            sum += A[j];
            sumA.push_back(sum);
        }
    }

    for (int i = 0; i < B.size(); i++) {
        long long sum = B[i];
        for (int j = i + 1; j < B.size(); j++) {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end());

    long long count = 0;
    for (auto a : sumA) {
        int diff = T - a;
        auto up = upper_bound(sumB.begin(), sumB.end(), diff);
        auto low = lower_bound(sumB.begin(), sumB.end(), diff);

        count += (up - low);
    }

    cout << count;
}