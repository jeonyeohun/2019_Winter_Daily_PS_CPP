#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> vec;
int maxNum;

int createNum() {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += pow(10, i) * vec[i];
    }

    return sum;
}

void dfs(int N, int K, vector<int>& nums) {
    int sum = createNum();
    if (sum > N) {
        return;
    }
    maxNum = max(maxNum, sum);

    for (int i = 0; i < K; i++) {
        vec.push_back(nums[i]);
        dfs(N, K, nums);
        vec.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> nums(K);
    for (int i = 0; i < K; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    dfs(N, K, nums);
    cout << maxNum;
}
