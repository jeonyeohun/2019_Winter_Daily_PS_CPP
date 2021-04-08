#include <iostream>

using namespace std;

long long calcSum(long long N) {
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        sum += i;
    }

    return sum;
}

long long binarySearch(long long target) {
    long long head = 1;
    long long tail = target;
    long long answer = 0;

    while (head <= tail) {
        long long mid = (head + tail) / 2;
        long long sum = calcSum(mid);

        if (target - sum >= mid) {
            answer = mid;
            head = mid + 1;
        }
        else {
            tail = mid - 1;
        }
    }

    return answer;
}

int main() {
    long long S;
    cin >> S;

    cout << binarySearch(S);

}