#include <iostream>
#include <vector>
#include <set>

using namespace std;

int M;
set<vector<int> > results;
vector<int> v;

bool isNonDesc (vector<int> nums){
    bool isT = true;
    for (int i = 1 ; i < nums.size() ; i++){
        if (nums[i] < nums[i-1]) isT = false;
    }
    if (isT) return true;
    return false;
}

void DFS (vector<int> numbers){
    if (v.size() == M){
        if (isNonDesc(v)) results.insert(v);
        return;
    }

    for (int i = 0 ; i < numbers.size() ; i++){
        v.push_back(numbers[i]);
        DFS(numbers);
        v.pop_back();
    }
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N >> M;
    
    vector<int> numbers;

    while(N--){
        int item;
        cin >> item;
        numbers.push_back(item);
    }
    
    DFS(numbers);

    for (auto  r : results){
        for (auto i : r){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;   
}