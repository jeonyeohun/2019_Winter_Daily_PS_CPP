#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M;
vector<int> result;

bool isNonDesc (vector<int> nums){
    bool isT = true;
    for (int i = 1 ; i < nums.size() ; i++){
        if (nums[i] < nums[i-1]) isT = false;
    }
    if (isT) return true;
    return false;
}

void DFS(int cnt, vector<int> &nums){
    if (cnt == M){
        if (isNonDesc(result)){
            for (auto r : result){
                cout << r << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 0 ; i < nums.size() ; i++){
        result[cnt] = nums[i];
        DFS(cnt+1, nums);
    }
}

int main (){
    int N;
    cin >> N >> M;

    vector<int> v;
    result.resize(M);

    while (N--){
        int in;
        cin >> in;
        v.push_back(in);
    }

    sort(v.begin(), v.end());
    DFS(0, v);
    
}