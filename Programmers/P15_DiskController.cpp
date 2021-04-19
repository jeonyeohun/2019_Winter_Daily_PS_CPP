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
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    queue<vector<int>> temp;
    sort(jobs.begin(), jobs.end(), cmp);

    pq.push(jobs.front());

    int used = 1;
    int endTime = 0;
    int timeSum = 0;
    int workTime;
    while (!pq.empty()) {
        vector<int> now = pq.top();
        pq.pop();

        cout << now[0] << " " << now[1] << endl;

        workTime = endTime - now[0] + now[1];
        endTime = now[0] + workTime;

        cout << "w : " << workTime << " e: " << endTime << "\n";
        timeSum += workTime;

        while (used < jobs.size() && now[1] >= jobs[used][0]) {
            if (jobs[used][0] <= now[1]) pq.push(jobs[used]);
            cout << "   " << jobs[used][0] << " " << jobs[used][1] << endl;
            used++;
        }
    }

    return timeSum / jobs.size();
}

int main() {
    cout << solution({ {0, 10}, {2, 10}, {9, 10}, {15, 2} }) << " 14";
}