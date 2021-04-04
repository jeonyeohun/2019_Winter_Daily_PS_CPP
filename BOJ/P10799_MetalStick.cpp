#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> stk;
    int answer = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(')
            stk.push('(');
        else {
            stk.pop();
            if (str[i - 1] == '(') answer += stk.size();
            else answer++;
        }
    }
    cout << answer;
}