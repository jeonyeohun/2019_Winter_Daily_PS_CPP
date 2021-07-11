#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N; cin >> N;
    stack<int> stk;
    vector<int> nums(N);
    vector<int> answer(N, -1);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < nums.size(); i++) {
        while (!stk.empty() && nums[stk.top()] < nums[i]) {
            answer[stk.top()] = nums[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (auto i : answer) {
        cout << i << " ";
    }
}
