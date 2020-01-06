#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main (){
    int N;
    vector<pair<int, int> > v;

    cin >> N;    
    while(N--){
        pair<int, int> p;
        cin >> p.first >> p.second;

        v.push_back(p);
    }


    for (auto iter = v.begin() ; iter != v.end() ; iter++){
        int k = 1; // 초기 등수를 1위로 초기화
        for (auto iter2 = v.begin(); iter2 != v.end() ; iter2++){
            if (iter->first < iter2->first && iter->second < iter2->second) k++; // 키와 몸무게가 더 큰 아이템이 나타날때마다 등수 하나씩 내리기 
        }
        cout << k << "\n"; // 등수 출력
    }
    return 0;
}