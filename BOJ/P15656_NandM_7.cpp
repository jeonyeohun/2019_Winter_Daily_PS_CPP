#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M;
vector<int> result;

void DFS(int cnt, vector<pair<int, bool>> &nums){
    if (cnt == M){
        for (auto r : result){
            cout << r << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0 ; i < nums.size() ; i++){
        result[cnt] = nums[i].first;
        DFS(cnt+1, nums);
    }


}

int main (){
    int N;
    cin >> N >> M;

    vector<pair<int, bool>> nums;
    result.resize(M);

    while(N--){
        int in;
        cin >> in;
        nums.push_back(make_pair(in, false));
    }

    sort(nums.begin(), nums.end());
    DFS(0, nums);

    return 0;
}