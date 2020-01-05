#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp (const pair<int, int> &a, const pair<int, int>&b){
    if(a.second < b.second) return true;
    else if (a.second == b.second) return a.first < a.second;
    return false;
}

int main (){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int, int> > v (N); // 페어벡터 만들고 최댓값으로 초기화

    for (int i = 0 ; i < N ; i++){
        int x, y;
        cin >> x >> y;
        v[i].first = x;
        v[i].second = y;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0 ; i < N ; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;

}
