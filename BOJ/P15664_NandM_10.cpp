#include <iostream>
#include <vector>
#include <set>

using namespace std;

int M;
vector<int> result;
set<vector<int>> s;

bool isNonDesc (vector<int> nums){
    bool isT = true;
    for (int i = 1 ; i < nums.size() ; i++){
        if (nums[i] < nums[i-1]) isT = false;
    }
    if (isT) return true;
    return false;
}

void DFS(vector<pair<int, bool>> vp){
    if (result.size() == M){
        if (isNonDesc(result)) s.insert(result);
        return;
    }

    for (int i = 0  ; i < vp.size() ; i++){
        if (!vp[i].second){
            vp[i].second = true;
            result.push_back(vp[i].first);
            DFS(vp);
            result.pop_back();
            vp[i].second = false; 
        }
    }

}

int main (){
    int N;
    cin >> N >> M;
    vector<pair<int, bool>> vp;

    while(N--){
        int in;
        cin >> in;
        vp.push_back(make_pair(in, false));
    }
    DFS(vp);

    for (auto it : s){
        for(auto i : it){
            cout << i << " ";
        }
        cout << "\n";
    }
    

    return 0;
}