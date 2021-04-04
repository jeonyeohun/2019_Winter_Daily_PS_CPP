#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string str;
    vector<double> operands(27, 0);
    stack<double> stk;

    cin >> N >> str;

    for (char c : str) {
        if (c != '-' && c != '*' && c != '+' && c != '/') {
            if (operands[c - 65] == 0) {
                int n;
                cin >> n;
                operands[c - 65] = n;
            }
        }
    }

    for (char c : str) {
        if (c != '-' && c != '*' && c != '+' && c != '/') {
            stk.push(operands[c - 65]);
        }
        else {
            auto rhs = stk.top();
            stk.pop();
            auto lhs = stk.top();
            stk.pop();

            switch (c) {
            case '-':
                stk.push(lhs - rhs);
                break;
            case '+':
                stk.push(lhs + rhs);
                break;
            case '*':
                stk.push(lhs * rhs);
                break;
            case '/':
                stk.push(lhs / rhs);
                break;
            }
        }
    }

    printf("%0.2f\n", stk.top());
}
