#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> positiveQ;
    priority_queue<int, vector<int>, greater<int>> negativeQ;
    stack<int> bucket;

    for (auto op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2, op.size() - 1));
            cout << num << " ";
            positiveQ.push(num);
            negativeQ.push(num);
        }
        else if (op[0] == 'D' && isdigit(op[2])) {
            if (positiveQ.empty()) continue;

            positiveQ.pop();

            for (int i = 0; i < positiveQ.size(); i++) {
                bucket.push(negativeQ.top());
                negativeQ.pop();
            }

            negativeQ.pop();

            while (!bucket.empty()) {
                negativeQ.push(bucket.top());
                bucket.pop();
            }
        }
        else if (op[0] == 'D' && !isdigit(op[2])) {
            if (negativeQ.empty()) continue;

            negativeQ.pop();

            for (int i = 0; i < negativeQ.size(); i++) {
                bucket.push(positiveQ.top());
                positiveQ.pop();
            }

            positiveQ.pop();

            while (!bucket.empty()) {
                positiveQ.push(bucket.top());
                bucket.pop();
            }
        }
    }

    if (positiveQ.empty()) return { 0, 0 };
    else return { positiveQ.top(), negativeQ.top() };
}