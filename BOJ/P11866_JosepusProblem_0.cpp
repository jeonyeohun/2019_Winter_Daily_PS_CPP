#include <iostream>
#include <vector>

using namespace std;

int main (){
    int N, K;
    cin >> N >> K;

    vector<int> v;
    vector<int> r;

    for (int i = 1 ; i <= N ; i++) v.push_back(i); // 아이템 채워넣기

    auto iter = v.begin();
    while(v.size()>0){
        if (iter == v.end()) iter = v.begin();
        for (int i = 0 ; i < K-1; i++){ // K-1 칸 이동하면서 마지막에 도달하면 그냥 맨 앞으로 이동
            if (*iter == v.back()) {
                iter = v.begin();
            }
            else iter++;
        }
        
        r.push_back(*iter);
        iter = v.erase(iter);
    }
    
    cout << "<";
    for (int i = 0 ; i < r.size() ; i++){
        if (i == r.size()-1) cout << r[i];
        else cout << r[i] << ", ";
    }
    cout << ">";
    
    return 0;
}
