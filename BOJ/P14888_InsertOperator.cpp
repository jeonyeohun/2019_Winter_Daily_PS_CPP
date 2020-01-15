#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

vector<string> ops;
vector<string> opset;
vector<vector<string>> result;
vector<bool> visited;

int calc(vector<int> nums, vector<string> op){
    int calc = nums.front();
    nums.erase(nums.begin());
    while(!op.empty()){
        if(!op.front().compare("X")) calc *= nums.front();
        else if(!op.front().compare("/")) calc /= nums.front();
        else if (!op.front().compare("-")) calc -= nums.front();
        else calc += nums.front();
        nums.erase(nums.begin());
        op.erase(op.begin());
    }
    return calc;
}

void back_tracking (int max){
    if (opset.size() == max) {
        result.push_back(opset);
        return;
    }
    
    for (int i = 0 ; i < ops.size() ; i++){
        if(!visited[i]){
            visited[i] = true;
            opset.push_back(ops[i]);
            back_tracking(max);
            opset.pop_back();
            visited[i] = false;
        }
    }
    
}

int main (){
    vector<int> nums;
    int N;
    cin >> N;
    while(N--){
        int n; cin >> n;
        nums.push_back(n);
    }
    for (int i = 0 ; i < 4 ; i++){
        int op; cin >> op;
        for (int j =0 ; j < op ; j++){
            string o;
            if (i == 0) o = "+";
            else if (i == 1) o = "-";
            else if (i == 2) o = "X";
            else if (i == 3) o = "/";
            ops.push_back(o);
        }
    }
    
    int max = ops.size();
    visited.resize(max, false);
    
    back_tracking(max);
    
    int MaxAns = INT_MIN;
    int MinAns = INT_MAX;
    for (auto v : result){
        int ans = calc(nums, v);
        if (ans > MaxAns) MaxAns = ans;
        if (ans < MinAns) MinAns = ans;
    }
    
    cout << MaxAns<< "\n" << MinAns;
    return 0;
}
