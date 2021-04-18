#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> lefts;

    for (int i = 0; i < progresses.size(); i++) {
        int leftOver = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) leftOver++;

        lefts.push(leftOver);
    }

    int now = lefts.front();
    int count = 0;

    while (!lefts.empty()) {
        if (now >= lefts.front()) {
            lefts.pop();
            count++;
        }
        else {
            answer.push_back(count);
            now = lefts.front();
            count = 0;
        }
    }

    if (count != 0) answer.push_back(count);

    return answer;
}