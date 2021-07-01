#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

bool isBalanced(deque<char> strQueue) {
    map<char, char> braceMap = { {')', '('}, {']', '['}, {'}', '{'} };
    stack<char> stk;

    while (!strQueue.empty()) {
        if (!stk.empty()
            && braceMap.find(strQueue.front()) != braceMap.end()
            && stk.top() == braceMap[strQueue.front()]) {
            stk.pop();
            strQueue.pop_front();
        }
        else {
            stk.push(strQueue.front());
            strQueue.pop_front();
        }
    }
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    deque<char> strDq(s.begin(), s.end());

    for (int i = 0; i < strDq.size(); i++) {
        if (isBalanced(strDq)) answer++;

        strDq.push_back(strDq.front());
        strDq.pop_front();
    }

    return answer;
}