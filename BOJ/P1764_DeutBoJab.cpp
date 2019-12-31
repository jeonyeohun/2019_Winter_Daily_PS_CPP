#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> dnames;
    set<string> bnames;
    set<string> result;

    int N, M;
    cin >> N >> M;

    int t = N+M;
    while(t--){
        string name;
        cin >> name;
        if(t >= M) dnames.insert(name); // 듣도 못한 이름들 넣기
        else bnames.insert(name);  // 보도 못한 이름들 넣기
    }
    // 셋은 넣을 때 자동으로 소팅이 되기 때문에 셋에 사용되는 find는 바이너리 서치(O(log n))를 사용한다. 일반 std::find 는 모든 원소를 다 검사하기 떄문에 O(n^2).
    for (set<string> :: iterator dit = dnames.begin() ; dit != dnames.end() ; dit++){
        if(bnames.find(*dit) != bnames.end()) result.insert(*dit); // 듣고 못한 이름중에 보도 못한 이름에 이름이 있는지 확인하고 결과셋에 넣기
    }

    // 결과 출력 //
    cout << result.size() << "\n";
    for (string r : result){
        cout << r << "\n";
    }
    return 0;
}