#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned long long binarySearch(unsigned long long target) {
    if (target == 0) return 0;

    unsigned long long head = 1;
    unsigned long long tail = sqrt(target);
    unsigned long long mid;

    while (head <= tail) {
        mid = (head + tail) / 2;
        if (mid < sqrt(target)) {
            head = mid + 1;
        }
        else {
            tail = mid - 1;
        }
    }

    return mid * mid == target ? mid : mid + 1;
}

int main() {
    unsigned long long n;
    cin >> n;
    cout << binarySearch(n);
}
