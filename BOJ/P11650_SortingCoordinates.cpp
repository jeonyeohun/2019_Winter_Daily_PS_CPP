#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main (){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int, int> > v (100001, {100001, 100001}); // 페어벡터 만들고 최댓값으로 초기화

    for (int i = 0 ; i < N ; i++){
        int x, y;
        cin >> x >> y;
        v[i].first = x;
        v[i].second = y;
    }
    sort(v.begin(), v.end());

    for (int i = 0 ; i < N ; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;

}
