#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

unsigned long long binarySearch(unsigned long long target) {
    unsigned long long head = 1;
    unsigned long long tail = target;
    unsigned long long mid;
    unsigned long long answer = ULLONG_MAX;

    while (head <= tail) {
        mid = (head + tail) / 2;
        unsigned long long square = mid * mid;
        if (square < target) {
            head = mid + 1;
        }
        else {
            answer = min(answer, mid);
            tail = mid - 1;
        }
    }
    return answer;
}

int main() {
    unsigned long long n;
    cin >> n;
    cout << binarySearch(n);
}
