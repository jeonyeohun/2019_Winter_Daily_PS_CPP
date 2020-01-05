#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers (9, 0);

void DFS (int cnt){
    if (cnt == M){
        for (int i = 0 ; i < M ; i++){
            cout << numbers[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 원래 자기자신은 건너뛰려고 visited 벡터를 만들어서 이미 들렀던 노드인지 확인하는 작업을 거쳤는데, 이 문제는 중복이 허용되기 때문에 그냥 매번 전부 다 순회하면 된다.
    for (int i = 1 ; i <= N ; i++){
        numbers[cnt] = i;
        DFS(cnt+1);
    }
}

int main (){
    cin >> N >> M;
    
    DFS(0);

    return 0;    
}
