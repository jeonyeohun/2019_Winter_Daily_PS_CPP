#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {

    sort(people.begin(), people.end(), greater<int>());
    deque<int> dq(people.begin(), people.end());

    int boatNum = 0;
    while (!dq.empty()) {
        int now = dq.front();
        dq.pop_front();

        if (!dq.empty() && now + dq.back() <= limit) {
            dq.pop_back();
        }
        boatNum++;
    }

    return boatNum;
}