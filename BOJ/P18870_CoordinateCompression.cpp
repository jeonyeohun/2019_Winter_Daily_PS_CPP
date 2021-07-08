#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> sortedNums;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sortedNums.assign(nums.begin(), nums.end());
    sort(sortedNums.begin(), sortedNums.end());
    sortedNums.erase(unique(sortedNums.begin(), sortedNums.end()), sortedNums.end());

    for (auto num : nums) {
        cout << lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin() << " ";
    }

}
