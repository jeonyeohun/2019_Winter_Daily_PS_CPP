#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    for (int i = 0; i < lost.size(); i++) {
        auto nowIter = find(reserve.begin(), reserve.end(), lost[i]);
        if (nowIter != reserve.end()) {
            lost.erase(lost.begin() + i);
            reserve.erase(nowIter);
            i--;
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        auto prevIter = find(reserve.begin(), reserve.end(), lost[i] - 1);
        auto nextIter = find(reserve.begin(), reserve.end(), lost[i] + 1);

        if (prevIter != reserve.end()) {
            lost.erase(lost.begin() + i);
            reserve.erase(prevIter);
            i--;
        }
        else if (nextIter != reserve.end()) {
            lost.erase(lost.begin() + i);
            reserve.erase(nextIter);
            i--;
        }

    }

    return n - lost.size();
}