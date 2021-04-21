#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int target, vector<int> citations) {
    int idx;
    for (idx = 0; idx < citations.size(); idx++) {
        if (citations[idx] >= target) break;
    }
    return (citations.size() - idx >= target);
}

int binarySearch(int max, vector<int> citations) {
    int head = 0;
    int tail = max;
    int maxH = 0;

    while (head <= tail) {
        int mid = (head + tail) / 2;
        bool valid = isValid(mid, citations);

        if (valid) {
            maxH = mid;
            head = mid + 1;
        }
        else {
            tail = mid - 1;
        }
    }
    return maxH;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    return binarySearch(citations.size(), citations);
}