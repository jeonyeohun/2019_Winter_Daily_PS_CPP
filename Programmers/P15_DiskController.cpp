#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    vector<bool> isUsed(jobs.size(), false);
    sort(jobs.begin(), jobs.end(), cmp);

    pq.push(jobs.front());

    int timeSum = 0;
    int endTime = (pq.top())[0];

    isUsed[0] = true;
    while (!pq.empty()) {
        vector<int> now = pq.top();
        pq.pop();

        timeSum += abs(endTime - now[0]) + now[1];
        endTime += now[1];

        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= endTime && !isUsed[i]) {
                pq.push(jobs[i]);
                isUsed[i] = true;
            }
        }

        if (pq.empty()) {
            for (int i = 0; i < jobs.size(); i++) {
                if (jobs[i][0] > endTime && !isUsed[i]) {
                    pq.push(jobs[i]);
                    isUsed[i] = true;
                    endTime = jobs[i][0];
                    break;
                }
            }
        }
    }

    return timeSum / jobs.size();
}

int main() {
    cout << solution({ {0, 10}, {2, 10}, {9, 10}, {15, 2} }) << " 14";
}