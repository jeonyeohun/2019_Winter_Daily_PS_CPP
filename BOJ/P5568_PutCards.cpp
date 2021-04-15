#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<string> comb;
vector<string> vec;
bool visited[11];

void dfs(int k, vector<string>& nums) {
    if (vec.size() == k) {
        string combStr = "";
        for (int i = 0; i < k; i++) {
            combStr += vec[i];
        }
        comb.insert(combStr);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            vec.push_back(nums[i]);
            dfs(k, nums);
            vec.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<string> nums(n);

    for (int i = 0;i < n; i++) {
        cin >> nums[i];
    }

    dfs(k, nums);

    cout << comb.size();

}
